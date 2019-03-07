
#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    string input;
    cout << "input" << endl;
    cin >> input;
    int check = 0;
    int answer = 0;
    for(int i = 0; i < input.length() - 1; i++){
        if(input[i] == '(' && input[i+1] == '('){
            check = check + 1;
        }else if(input[i] == '(' && input[i+1] == ')'){
            answer = answer + check;
        }else if(input[i] == ')' && input[i+1] == ')'){
            check = check - 1;
            answer = answer + 1;
        }
    }
    cout << answer << endl;
    return 0;
}
