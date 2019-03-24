//
//  main.cpp
//  7576_tomato
//
//  Created by 잉뿌 on 24/03/2019.
//  Copyright © 2019 잉뿌. All rights reserved.
//


#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 1000000;

vector<int> tomato[MAX];    //토마토 좌표에 따른 정보 기록.
queue<pair<int,int>> q_Ripe;    //익은 토마토 좌표 기록.

int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};   //상하좌우 좌표 계산용


int main(int argc, const char * argv[]) {
    cout << "TAETAE START\n";
    
    int M,N;
    
    cin >> M >> N;
    
    for(int i=0 ; i<N ; i++) for(int j=0 ; j<M ; j++){
        int a;
        cin >> a;
        tomato[i].push_back(a);
        if(a==1){
            q_Ripe.push(make_pair(i,j));//익은 토마토 좌표를 큐에 넣자
        }
    }
    
    if(q_Ripe.empty()){ //처음부터 익은게 1도 없음. 저절로 못익기 때문에 모두 익지못함.
        cout << -1 << '\n';
        return 0;
    }
    
    while(!q_Ripe.empty()){
        int x = q_Ripe.front().first;
        int y = q_Ripe.front().second;
        
        q_Ripe.pop();
        
        for(int i=0 ; i<4 ; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx>=0 && nx<N && ny>=0 && ny<M && tomato[nx][ny]==0)
            {
                 //-1 이면 토마토가 없는곳이니깐!
                    tomato[nx][ny] = tomato[x][y] + 1;
                    q_Ripe.push(make_pair(nx,ny));
            }
        }
    }
    
    
    //하나라두 안익은 토마토가 있는 경우
    for(int i=0 ; i<N ; i++) for(int j=0 ; j<M ; j++){
        if(tomato[i][j]==0){
            cout << -1 << '\n';
            return 0;
        }
    }
    
    //day 계산
    int day=0;
    
     for(int i=0 ; i<N ; i++) {
        for(int j=0 ; j<M ; j++){
            if(tomato[i][j] > day)    day = tomato[i][j];
        }
     }
     
    cout << day-1 << '\n';
    
    cout << "THE END\n";
    
    return 0;
}

