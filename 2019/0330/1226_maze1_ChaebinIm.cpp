//
//  main.cpp
//  AlgorithmStudy_19
//
//  Created by 임채빈 on 05/04/2019.
//  Copyright © 2019 임채빈. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
int maze[16][16]; //maze는 입력받은 미로
bool visited[16][16]; //visited는 방문여부(dfs의 연산량을 줄이기 위함)
stack<pair<int,int>> st; //st는 dfs를 위한 stack, 방문'할' 곳을 가리킴.
int dx[4] = {1,0,-1,0}; // dx, dy는 상하좌우탐색을 위한 장치
int dy[4] = {0,1,0,-1};
bool arrival = false; //arrival은 결과를 보는거임. 3을 찾았냐 못찾았냐의 여부를 가리킴. 찾음(true), 못찾음(false)
//dfs 시작
void dfs(){
    int x, y, nx, ny;
    while(!st.empty()){
        //현재 위치를 기록
        x = st.top().first;
        y = st.top().second;
        //stack pop해줌.
        st.pop();
        for(int i = 0; i < 4; i++){
            //다음 방문할 곳을 탐색
            nx = x + dx[i];
            ny = y + dy[i];
            //일단 3을 찾으면 무조건 끝난거임. 목적지를 찾은 것.
            if(maze[nx][ny] == 3){
                arrival = true;
                break;
            //다음 방문할 곳이 목적지가 아니라면, 더 방문할 곳이 있는지를 탐색함. 있다면 st에 추가해줌.
            }else if(maze[nx][ny] == 0 && !visited[nx][ny]){
                st.push(make_pair(nx,ny));
                visited[nx][ny] = true;
            }
        }
        //3을 찾았다면, 더이상 볼 필요도 없이 함수를 끝냄.
        if(arrival)
            break;
    }
}




int main(int argc, const char * argv[]) {
    cout << "start!" << endl;
    for(int test = 1; test <= 10; test++){
        cin >> test;
        //원활한 진행을 위해 전체를 초기화시켜줌.
        //먼저, stack 초기화(비워놓기)
        while(!st.empty())
            st.pop();
        //이후에 visited를 모두 false로 놓음.
        for(int i = 0; i < 16; i++){
            for(int j = 0; j < 16; j++){
                visited[i][j] = false;
                int input;
                scanf("%1d", &input);
                maze[i][j] = input;
                //input으로 2가 입력되면, 시작점을 의미하므로, st에 추가해줌. 이는 이후 탐색의 시작지점이 됨.
                if(input == 2){
                    st.push(make_pair(i,j));
                    visited[i][j] = true;
                }
            }
        }
        //dfs이전에 도착여부 초기화.
        arrival = false;
        //dfs 실행.
        dfs();
        //목적지에 도착했다면(3을 찾았다면) 1을 출력, 아니면 0을 출력.
        if(arrival){
            cout << "#" << test << " " << 1 << endl;
        }else{
            cout << "#" << test << " " << 0 << endl;
        }
    }
    return 0;
}
