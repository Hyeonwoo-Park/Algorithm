//
//  main.cpp
//  AlgorithmStudy_17
//
//  Created by 임채빈 on 29/03/2019.
//  Copyright © 2019 임채빈. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;


int main(int argc, const char * argv[]) {
    cout << "start!" << endl;
    //num_case는 test case 수.
    int num_case;
    scanf("%d", &num_case);
    //n은 시험의 문제 수
    int n;
    for(int i = 0; i < num_case; i++){
        //answer는 'A'는 1, 'B'는 2, 'C'는 3, 'D'는 4로 표현된 각 문제당 아이들이 푼 답.
        char answer[3][30001];
        //correct_count는 각 아이들이 문제를 해결한 수를 적은 것.
        int correct_count[3] = {0, 0, 0};
        //not_same은 아이들이 입력한 답이 전부 다를 경우를 카운트
        int not_same = 0;
        //cin >> n;
        scanf("%d", &n);
        //일단 문제와 아이들이 정한 답을 입력받겠다.
        //cin >> answer[0] >> answer[1] >> answer[2];
        scanf("%s %s %s", answer[0], answer[1], answer[2]);
        /* 이후부터는 3가지 케이스로 나뉜다.
        1. 3명이 입력한 값이 다 같을경우
        2. 2명만 같을경우
        3. 다 다를 경우
        이를 고려하여 대처해준다.
        1 -> 다 카운트해주면됨
        2 -> 두명인 곳을 우선적으로 카운트 해줌
        3 -> 나중에 고려하도록 하겠다.
        */
        for(int j = 0; j < n; j++){
            if(answer[0][j] == answer[1][j] && answer[1][j] == answer[2][j]){
                correct_count[0]++;
                correct_count[1]++;
                correct_count[2]++;
            }else if(answer[0][j] == answer[1][j]){
                correct_count[0]++;
                correct_count[1]++;
            }else if(answer[0][j] == answer[2][j]){
                correct_count[0]++;
                correct_count[2]++;
            }else if(answer[2][j] == answer[1][j]){
                correct_count[1]++;
                correct_count[2]++;
            }else{
                not_same++;
            }
        }
        /* 위의 3의 경우(나중에 고려하는 부분)을 고려할 차례.
        일단 모두가 수가 다를 경우에는, 당연히 그렇듯 제일 적게 문제를 맞춘 친구를 맞다고 해준다.
        */
        sort(correct_count, correct_count+3);
        for(int j = not_same; j>0; j--){
            correct_count[0]++;
            if(correct_count[0]>correct_count[1])
                sort(correct_count, correct_count+3);
        }
        /*
        하지만 이렇게 한다고 해서 끝난게 아님. 혹시나 그 수가 부족할 수도 있기 때문. 
        이 때에 중요한 점은 한 사람이 맞추면 다른 한사람은 틀리게 된다는 점을 이용해서 인위적으로 맞춘 문제 수를 억지로 조정해준다.
        */
        while(correct_count[0] < correct_count[1]){
            correct_count[0]++;
            correct_count[1]--;
            if(correct_count[0] > correct_count[1])
                sort(correct_count, correct_count+3);
        }
        printf("#%d %d", i+1, correct_count[0]);
    }
    
    return 0;
}

