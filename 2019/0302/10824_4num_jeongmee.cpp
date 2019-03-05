#include <iostream>
#include <math.h>
using namespace std;
int cal(long long number){
    
    int ans = 0;
    
    while(number>0){
        number/=10;
        ans++;
    }
    
    return ans;
}

int main() {
	  long long a,b,c,d;
    int num = 0;
    long long answer = 0;
	  cin >> a >> b >> c >> d;
  
    num = cal(b);
    answer = (pow(10,num)*a) + b;
    num = cal(d);
    answer += (pow(10,num)*c) + d;
    
    cout << answer;
    
	  return 0;
}
