//
//  main.cpp
//  AlgorithmStudy_11
//
//  Created by 임채빈 on 21/03/2019.
//  Copyright © 2019 임채빈. All rights reserved.
//

#include <iostream>
#include <algorithm>
#define MAX 100001
using namespace std;
//candidate는 개체를 체크 시작하는 원점
int candidate = 0;
//cnt는 무한 회전하는 경우를 고려하여 만듬
int cnt;
int student_num;
// made는 group이 만들어졌는지를 체크
bool made[MAX];
// want는 각 인덱스에 해당하는 개체가 원하는 짝꿍
int want[MAX];

void dfs(int i){
    //그룹이 만들어진 개체는 고려할 필요 x AND 개체 수만큼 회전을 한 경우에는 짝이 없어야됨.
    if(made[candidate] || cnt > student_num)
        return;
    //현재 개체가 원하는 짝꿍이 next
    int next = want[i];
    //만약 원하는 애가 기준이라면, 회전이 끝난다.
    if(next == candidate){
        made[candidate] = true;
        made[i] = true;
    }else{ //원하는 애가 기준이 아니라면, 회전수를 채우거나, 원하는 애가 기준이 될때 까지 회전할 것.
        cnt++;
        dfs(next);
        //회귀가 끝나고 기준점의 짝꿍이 정해진다면, 그 과정에 거친 개체들도 다 그룹이 형성됨.
        if(made[candidate]){
            made[i] = true;
        }
    }
}

int main(int argc, const char * argv[]) {
    cout << "start" << endl;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int num_case;
    cin >> num_case;
    int answer, j;
    for(int i = 0; i < num_case; i++){
        answer = 0;
        cin >> student_num;
        fill(made, made + student_num+1, false);
        fill(want, want + student_num+1, 0);
        //먼저, 원하는 짝꿍을 입력하는데, 자기 자신 혼자하길 원하면 1인 그룹을 형성해줌.
        for(j = 1; j <= student_num; j++){
            cin >> want[j];
            if(want[j] == j){
                made[j] = true;
            }
        }
        // 기준점(candidate)를 잡고 짝꿍 만드는 과정을 시작(dfs)
        for(j = 1; j <= student_num; j++){
            if(!made[j]){
                cnt = 0;
                candidate = j;
                dfs(j);
            }
            //answer는 최종 출력할 그룹에 포함되지 않은 친구들.
            if(!made[j])
                answer += 1;
        }
        cout << answer << "\n";
    }
    return 0;
}
