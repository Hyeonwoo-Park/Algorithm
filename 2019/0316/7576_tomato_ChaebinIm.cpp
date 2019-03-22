//
//  main.cpp
//  AlgorithmStudy_12
//
//  Created by 임채빈 on 21/03/2019.
//  Copyright © 2019 임채빈. All rights reserved.




// pair 써야될듯

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define MAX 1001
using namespace std;
//matrix는 2차원 행렬(입력 받는 값), 테두리는 -1로 뒤에 채움.
int matrix[MAX][MAX];
//willvisit은 중복을 줄이기 위한 방문여부를 체크하는 용도.
bool willvisit[MAX][MAX];
//q는 정상 토마토(1)를 체크하기 위한 큐
queue<pair<int, int>> q;

//searchNeighbor는 상, 하, 좌, 우 를 살피고 0이고, 중복이 안되었을 시, q에 위치를 저장하는 구조.
//맨 뒤의 부분에서 0이었던 값을 1로 바꿔준다!
void searchNeighbor(pair<int, int> p){
    if(matrix[p.first+1][p.second] == 0 && !willvisit[p.first+1][p.second]){
        pair<int, int> p1 = make_pair(p.first+1, p.second);
        q.push(p1);
        willvisit[p.first+1][p.second] = true;
    }
    if(matrix[p.first-1][p.second] == 0 && !willvisit[p.first-1][p.second]){
        pair<int, int> p1 = make_pair(p.first-1, p.second);
        q.push(p1);
        willvisit[p.first-1][p.second] = true;
    }
    if(matrix[p.first][p.second+1] == 0 && !willvisit[p.first][p.second+1]){
        pair<int, int> p1 = make_pair(p.first, p.second+1);
        q.push(p1);
        willvisit[p.first][p.second+1] = true;
    }
    if(matrix[p.first][p.second-1] == 0 && !willvisit[p.first][p.second-1]){
        pair<int, int> p1 = make_pair(p.first, p.second-1);
        q.push(p1);
        willvisit[p.first][p.second-1] = true;
    }
    matrix[p.first][p.second] = 1;
}


int main(int argc, const char * argv[]) {
    //input값을 받고, 테두리에 -1을 씌어준다. (BFS에서 밖으로 엇나가는 것을 막기위해 -1의 프레임을 씌움)
    int M, N, count;
    cout << "start" << endl;
    cin >> M >> N;
    for(int i = 0; i <= M+1; i++){
        matrix[0][i] = -1;
        matrix[N+1][i] = -1;
    }
    for(int j = 0; j <= N+1; j++){
        matrix[j][0] = -1;
        matrix[j][M+1] = -1;
    }
    
    //willvisit의 값들을 false로 초기화하고, 상한 토마토, 정상 토마토, 토마토가 없는 부분을 입력받음.
    //여기서 초기 정상토마토의 위치를 q에 저장.
    for(int i = 1; i <= N; i++){
        fill(willvisit[i], willvisit[i]+M, false);
        for(int j = 1; j <= M; j++){
            cin >> matrix[i][j];
            if(matrix[i][j] == 1){
                pair<int, int> p1 = make_pair(i,j);
                q.push(p1);
                willvisit[i][j] = true;
            }
        }
    }
    //count는 최종 출력할 값(날수)
    count = 0;
    //vp는 그날 방문할 위치를 포함하는 벡터(pair타입)
    vector<pair<int, int>> vp;
    while(!q.empty()){
        //정상토마토(1)의 위치를 벡터 vp에 넣고, 큐 q를 비운다.
        while(!q.empty()){
            vp.push_back(q.front());
            q.pop();
        }
        //벡터에 포함된 위치 전체의 상하좌우를 살피며, 다음날 영향을 미칠(방문할)위치를 탐색하여 q에 넣음.
        for(int i = 0; i < vp.size(); i++){
            searchNeighbor(vp[i]);
        }
        //벡터를 비운다.
        vp.clear();
        //밤이 되었습니다. (하루가 지난다)
        count++;
    }
    
    /*
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }*/
    //check하는 과정. 0이 있으면 모든 날이 지났음에도 불구하고, 토마토가 익지 않은 것이므로, -1을 출력.
    //fail이라는 변수로 전체가 다 익었는지, 아니면 익지 않았는지를 탐색. (하나라도 0이 있으면 -1)
    bool fail = false;
    for(int i = 1; i <= N; i++)
        if(!fail){
            for(int j = 1; j <= M; j++)
                if(matrix[i][j] == 0){
                    fail = true;
                    break;
                }
        }else{
            break;
        }
    //출력하는 부분
    if(fail){
        cout << -1 << endl;
    }else{
        cout << count-1 << endl;
    }
    
    return 0;
}
