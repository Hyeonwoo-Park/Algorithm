//
//  main.cpp
//  AlgorithmStudy_15
//
//  Created by 임채빈 on 26/03/2019.
//  Copyright © 2019 임채빈. All rights reserved.
//

#include <iostream>
#include <algorithm>
#define MAX 20

using namespace std;
//H는 직원들 각자 키, N은 직원 수, B는 기준, min은 최솟값
int H[MAX], N, B;
int min_ = 200001;

void dp(int now, int sum){
    if(now > N) return;
    if(sum >= B){
        //기준(B)보다 큰 모든 경우 중 최솟값을 뽑아내겠다.
        if(sum < min_)
            min_ = sum;
    }
    //모든 경우를 살펴보도록 하겠다. (Dynamic Programming)
    dp(now+1, sum);
    dp(now+1, sum+H[now]);
}


int main(int argc, const char * argv[]) {
    cout << "start" << endl;
    //T는 test case, S는 합.
    int T;
    //int S;
    cin >> T;
    for(int i = 0; i < T; i++){
        cin >> N >> B;
        //S = 0;
        for(int j = 0; j < N; j++)
            cin >> H[j];
        min_ = 2000001;
        dp(0, 0);
        cout << "#" << i+1 << " " << min_-B << endl;
    }
    
    
    return 0;
}
