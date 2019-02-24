

#include <iostream>
using namespace std;

int intbox[1000];

int OneTwoThree(int n){
    if(intbox[n] == 0 && n != 0){
        intbox[n] = OneTwoThree(n-1) + OneTwoThree(n-2) + OneTwoThree(n-3);
        return intbox[n];
    }else{
        return intbox[n];
    }
}

int main(int argc, const char * argv[]) {
    int T;
    cout << "start" << endl;
    cin >> T;
    int inputNum[T];
    intbox[0] = 0;
    intbox[1] = 1;
    intbox[2] = 2;
    intbox[3] = 4;
    for(int i = 0; i < T; i++){
        cin >> inputNum[i];
    }
    for(int i = 0; i < T; i++){
        if(inputNum[i] <= 3){
            cout << intbox[inputNum[i]] << endl;
        }else{
            OneTwoThree(inputNum[i]);
            cout << intbox[inputNum[i]] << endl;
        }
    }
    
    return 0;
}
