//
//  main.cpp
//  AlgorithmStudy_1
//
//  Created by 임채빈 on 06/03/2019.
//  Copyright © 2019 임채빈. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    cout << "input" << endl;
    long long a, b, c, d;
    cin >> a >> b >> c >> d;
    int count1, count2;
    count1 = count2 = 0;
    int check = (int)b;
    while(check >= 1){
        count1++;
        check = check/10;
    }
    check = (int)d;
    while(check >= 1){
        count2++;
        check = check/10;
    }
    long long sum1, sum2;
    for(int i = 0; i < count1; i++){
        a = a * 10;
    }
    sum1 = a + b;
    for(int i = 0; i < count2; i++){
        c = c * 10;
    }
    sum2 = c + d;
    cout << sum1 + sum2 << endl;
    return 0;
}
