//
//  main.cpp
//  AlgorithmStudy_16
//
//  Created by 임채빈 on 28/03/2019.
//  Copyright © 2019 임채빈. All rights reserved.
//

#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
int main(int argc, const char * argv[]) {
    cout << "start!" << endl;
    //num_case는 test case의 갯수
    int num_case;
    cin >> num_case;
    //jump는 초기에 받은 jump대 각각의 높이 (0번째부터 n-1번째까지)
    vector<int> jump;
    //n은 jump대의 갯수
    int n;
    //new_jump는 새롭게 배치된 jump대 정렬방식 저장.
    /*
     new_jump를 구성하는 방식은 다음과 같다.
     예를 들어서 1 4 5 3 2 라는 높이 순서의 jump대 기존 배치가 있다면,
     이것들을 우선 정렬한다 : 1 2 3 4 5
     그리고 앞에서부터 하나씩 배열하는데, 하나는 앞에서부터, 하나는 뒤에서부터 놓는다.
     결과적으로는 1 3 5 4 2 이렇게 된다. 그래서 이 문제의 답은 2가 된다.
     아래의 32번째줄부터의 for문은 이것을 나타낸 것이다.
     */
    vector<int> new_jump;
    for(int i = 0; i < num_case; i++){
        cin >> n;
        for(int j = 0; j < n; j++){
            int input;
            cin >> input;
            jump.push_back(input);
        }
        sort(jump.begin(), jump.end());
        for(int j = 0; j < n; j+=2){
            new_jump.push_back(jump[j]);
        }
        if(jump.size()%2 == 0){
            for(int j = n-1; j >= 1; j-=2)
                new_jump.push_back(jump[j]);
        }else{
            for(int j = n-2; j >= 1; j-=2)
                new_jump.push_back(jump[j]);
        }
        int max = 0;
        for(int j = 0; j < new_jump.size()-1; j++){
            if(abs(new_jump[j]-new_jump[j+1]) > max)
                max = abs(new_jump[j]-new_jump[j+1]);
            cout << new_jump[j] << " ";
        }
        cout << new_jump[n-1];
        if(abs(new_jump[n-1]-new_jump[0]) > max)
            max = abs(new_jump[n-1]-new_jump[0]);
        cout << "#" << i+1 << " " << max << endl;
        jump.clear();
        new_jump.clear();
    }
    
    return 0;
}
