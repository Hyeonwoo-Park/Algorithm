

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    int answer[31] = {1, 0, 3, };
    int input;
    cout << "input" << endl;
    cin >> input;
//(1)2
//(2)2+f(2)*2
//(3)2+f(2)*2+f(4)*2 ...
    if(input >= 4){
        for(int i = 4; i <= input; i += 2){
            answer[i] = answer[i-2] * answer[2];
            for(int j = 4; j <= i; j += 2){
                answer[i] = answer[i] + 2*answer[i-j];
            }
        }
    }
    cout << answer[input] << endl;
    
    return 0;
}
