//
//  main.cpp
//  AlgorithmStudy_18
//
//  Created by 임채빈 on 02/04/2019.
//  Copyright © 2019 임채빈. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int map[100][100]; //map은 처음 입력받은 지도
int min_distance[100][100]; //min_distance는 계속해서 수정해 가는 현재 위치를 오는 가장 짧은 경로.
bool visited[100][100]; //방문하였는지 여부를 체크하는 배열 -> 연산량을 줄이는데 중요!
queue<pair<int, int>> q; //BFS를 위한 queue
pair<int, int> p; //q에 넣기 위한 pair<int,int>타입의 변수 -> 솔직히 필요없다.
int size; //전체 사이즈
int dx[4] = {1,0,-1,0}; //상하좌우 방문을 위한 구조
int dy[4] = {0,1,0,-1}; //이하동문.


void bfs(int x, int y){
    // 일단 방문했는지를 확인한다 -> 쓸데없는 과정. 없어도됨.
    if(visited[x][y]) return;
    // 방문하였음을 표시. (사실 0,0을 방문하였음을 표시하는 것임)
    visited[x][y] = true;
    // q에 (0,0)을 넣겠다 -> 본격적으로 시작해 보겠다.
    p = make_pair(x, y);
    q.push(p);
    // q가 빌 때까지 하겠다. q가 빈다는 것은 모든 min_distance가 최솟값을 가지고, 모든 경로를 방문하였음을 의미.
    while(!q.empty()){
        //x, y는 현재 방문하고 있는 곳의 (x,y)좌표
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            //새롭게 방문할 곳의 (x,y)좌표를 정의
            int new_x = x + dx[i];
            int new_y = y + dy[i];
            //새로 방문할 곳의 (x,y)값이 0보다 크고, map의 size보다 작다면, (즉 index 범위를 벗어나지 않는다면,)
            if(new_x >= 0 && new_x < size && new_y >= 0 && new_y < size){
                // 아직 방문한 곳이 아니라면?
                if(!visited[new_x][new_y]){
                    //방문을 하겠다. 그리고 그 주변을 한번 더 고려하겠다.
                    visited[new_x][new_y] = true;
                    p = make_pair(new_x, new_y);
                    q.push(p);
                    //최소 거리를 최신화시켜주겠다.
                    min_distance[new_x][new_y] = min_distance[x][y] + map[new_x][new_y];
                    //만약 방문을 이미 한 곳이지만, 그 거리가 최소 거리가 아니라면?
                }else if(min_distance[new_x][new_y] > min_distance[x][y] + map[new_x][new_y]){
                    //최소 거리로 최신화하겠다. 그리고 한번 더 그 주변을 고려하겠다.
                    p = make_pair(new_x, new_y);
                    q.push(p);
                    min_distance[new_x][new_y] = min_distance[x][y] + map[new_x][new_y];
                }else
                    continue;
            }
        }
        
        
        
    }
    
    
}



int main(int argc, const char * argv[]) {
    cout << "start!" << endl;
    int num_case;
    cin >> num_case;
    for(int i = 1; i <= num_case; i++){
        //입력받을거 입력받겠다.
        cin >> size;
        //일단 최신화 시켜주자. 혹시나 다른 test case의 정보와 겹칠 수 있으니..
        for(int j = 0; j < 100; j++){
            for(int k = 0; k < 100; k++){
                map[j][k] = 0;
                min_distance[j][k] = 0;
                visited[j][k] = false;
            }
        }
        for(int j = 0; j < size; j++){
            for(int k = 0; k < size; k++){
                int input;
                scanf("%1d", &input);
                map[j][k] = input;
            }
        }
        //(0,0)부터 읽겠다.
        bfs(0,0);
        cout << "#" << i << " " << min_distance[size-1][size-1] << endl;
    }
    return 0;
}


/*
 DP로 푼 것.  -> 모든 경우의 경로 합을 구한 후, 그 최솟값을 출력하는 구조 -> 비효율적.
 위의 BFS의 경우에는 이미 방문한 곳은 방문하지 않는다 -> 연산량이 DP에 비해 극명하게 줄어듦.
 #include <iostream>
 #include <algorithm>
 using namespace std;
 int map[100][100];
 int size;
 int _min = 2147483647;
 void dp(int j, int k, int sum){
    sum = sum + map[j][k];
    if(j == size-1 && k == size-1){
        if(sum < _min){
            _min = sum;sum = 0;
        }
    }else if(j == size-1){
        dp(j, k+1, sum);
    }else if(k == size-1){
        dp(j+1, k, sum);
    }else{dp(j+1, k, sum);
        dp(j, k+1, sum);
    }
    return;
}
 
int main(int argc, const char * argv[]){
    int num_case;
    int sum = 0;
    cin >> num_case;
    for(int i = 1; i <= num_case; i++){
        cin >> size;
        for(int j = 0; j < size; j++){
            for(int k = 0; k < size; k++){
                int input;
                scanf("%1d", &input);
                map[j][k] = input;
            }
        }
        dp(0, 0, sum);
        cout << "#" << i << " " << _min << endl;
    }
    return 0;
 }
 */
