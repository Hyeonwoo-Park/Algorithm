//
//  main.cpp
//  AlgorithmStudy_21
//
//  Created by 임채빈 on 10/04/2019.
//  Copyright © 2019 임채빈. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;
//plan은 문제의 Ti이다. 즉, 상담을 완료하는데 걸리는 기간이다.
int plan[16] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
//payment는 상담을 완료했을 때, 받을 수 있는 돈이다.
int payment[16] = {0,};
//total_sum은 각 경우에서 payment가 더해진 값이다.
int total_sum = 0;
//n은 문제에서 처음 입력받는 (몇일)뒤에 퇴사할 것인가에 대한 정보이다.
int n;
//dp는 다이나믹 프로그래밍을 사용하여 이 문제를 풀기 위해 만든 함수이다.
void dp(int now, int sum){
    //day는 현재 오늘 수행할 수 있는 상담에 걸리는 시간이다.
    int day = plan[now];
    //price는 오늘 수행할 수 있는 일을 마쳤을 때 받을 수 있는 보수이다.
    int price = payment[now];
    //now>n+1이라는 것은 내가 퇴사할 날이 되었다는 의미이다.
    if(now > n+1){
        //최댓값을 찾기 위한 노력이다.
        if(sum+price > total_sum)
            total_sum = sum+price;
        return;
    }
    //dp를 돌리는 과정에서 만약, 퇴사 전날에 2일 걸리는 상담을 하면 일정 보수를 준다고 했을 때에 그것을 수행 할 수 없기 때문에 넣은 if-else문이다.
    if(now+day > n+1){
        dp(now+day, sum);
    }else{
        //여기서 중요한 것은, 그 상담을 진행할 수도 있고,
        dp(now+day, sum+price);
    }
    //진행하지 않을 수도 있다는 것이다.
    dp(now+1, sum);
    
}

int main(int argc, const char * argv[]) {
    cout << "start!" << endl;
    //각 문제의 조건에 맞게 입력받는다.
    cin >> n;
    for(int i = 1; i<= n; i++) cin >> plan[i] >> payment[i];
    //dp 실행한다.
    dp(0,0);
    //최종 값을 출력한다.
    cout << total_sum << endl;
    
    return 0;
}
