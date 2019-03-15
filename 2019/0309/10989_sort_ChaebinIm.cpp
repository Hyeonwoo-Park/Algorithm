
//
//  main.cpp
//  AlgorithmStudy_6
//
//  Created by 임채빈 on 14/03/2019.
//  Copyright © 2019 임채빈. All rights reserved.
//

#include <iostream>
#include <queue>
#define maxsize 10000000
using namespace std;
queue<int> q1;
queue<int> q2;
queue<int> q3;
queue<int> q4;
queue<int> q5;
queue<int> q6;
queue<int> q7;
queue<int> q8;
queue<int> q9;
queue<int> q0;
int input[maxsize];
void pushQueue(int input, int degree){
    switch((input/degree)%10){
        case 1: q1.push(input); break;
        case 2: q2.push(input); break;
        case 3: q3.push(input); break;
        case 4: q4.push(input); break;
        case 5: q5.push(input); break;
        case 6: q6.push(input); break;
        case 7: q7.push(input); break;
        case 8: q8.push(input); break;
        case 9: q9.push(input); break;
        case 0: q0.push(input); break;
        default : break;
    }
}
void popQueue(){
    int i = 0;
    while(!q0.empty()){
        input[i] = q0.front();
        q0.pop();
        i++;
    }
    while(!q1.empty()){
        input[i] = q1.front();
        q1.pop();
        i++;
    }
    while(!q2.empty()){
        input[i] = q2.front();
        q2.pop();
        i++;
    }
    while(!q3.empty()){
        input[i] = q3.front();
        q3.pop();
        i++;
    }
    while(!q4.empty()){
        input[i] = q4.front();
        q4.pop();
        i++;
    }
    while(!q5.empty()){
        input[i] = q5.front();
        q5.pop();
        i++;
    }
    while(!q6.empty()){
        input[i] = q6.front();
        q6.pop();
        i++;
    }
    while(!q7.empty()){
        input[i] = q7.front();
        q7.pop();
        i++;
    }
    while(!q8.empty()){
        input[i] = q8.front();
        q8.pop();
        i++;
    }
    while(!q9.empty()){
        input[i] = q9.front();
        q9.pop();
        i++;
    }
}

int main(int argc, const char * argv[]) {
    int n;
    cout << "input" << endl;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> input[i];
    
    for(int i = 0; i < n; i++){
        pushQueue(input[i], 1);
    }
    popQueue();
    for(int i = 0; i < n; i++){
        pushQueue(input[i], 10);
    }
    popQueue();
    for(int i = 0; i < n; i++){
        pushQueue(input[i], 100);
    }
    popQueue();
    for(int i = 0; i < n; i++){
        pushQueue(input[i], 1000);
    }
    popQueue();
    for(int i = 0; i < n; i++){
        pushQueue(input[i], 10000);
    }
    popQueue();
    
    for(int i = 0; i < n; i++){
        cout << input[i] << endl;
    }
    return 0;
}
