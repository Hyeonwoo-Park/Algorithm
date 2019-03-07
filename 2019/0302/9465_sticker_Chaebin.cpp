
#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    
    int N;
    cin >> N;
    int answer[N];
    int width;
    for(int i = 0; i < N; i++){
        cin >> width;
        int matrix[2][100001];
        int summat[2][100001];
        matrix[0][0] = 0;
        matrix[1][0] = 0;
        summat[0][0] = 0;
        summat[1][0] = 0;
        for(int j = 0; j < 2*width; j++){
            if(j < width){
                cin >> matrix[0][j+1];
            }else{
                cin >> matrix[1][j-width+1];
            }
        }
        for(int j = 1; j <= width; j++){
            if(j == 1){
                summat[0][1] = matrix[0][1];
                summat[1][1] = matrix[1][1];
            }else{
                summat[0][j] = max(summat[1][j-1], summat[1][j-2])+ matrix[0][j];
                summat[1][j] = max(summat[0][j-1], summat[0][j-2])+ matrix[1][j];
                }
        }
        answer[i] = max(summat[0][width], summat[1][width]);
    }
    
    for(int i = 0; i < N; i++){
        cout << answer[i] << endl;
    }
    
    
    return 0;
}
int max(int a, int b){
    if(a > b)
        return a;
    return b;
}
