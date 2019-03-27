
#include <iostream>
#include <vector>
#define MAX 20
using namespace std;
int tile[MAX][MAX];
bool made[MAX][MAX];
int tile2[MAX][MAX];
vector<int> after;
int N;
/*
 제가 사용한 방법은 다음과 같습니다.
 일단 tile이라는 int타입 2차원 배열에 값들을 넣습니다.
 left 함수를 쓴다고 가정하겠습니다.
 일단, 한 줄씩 살펴봅니다.
 그리고 한 줄을 볼 때에, 0이 아닌 값을 0이라는 int타입 벡터인 row에 저장합니다.
 그리고 그것들을 바탕으로, 두개씩 보면서 같은 숫자인지 확인함과 동시에 더해져서 만들어진 수인지(made : bool타입 2차원배열) 확인합니다.
 그리고 결과들을 순서대로 after라는 int 타입 vector에 저장합니다.
 마지막으로, tile2라는 0으로 가득찬 2차원 int타입 배열에 after의 값들을 넣습니다.
 그리고 출력합니다.
 */
void left(){
    vector<int> row;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(tile[i][j] != 0) row.push_back(tile[i][j]);
        }
        for(int j = 0; j < row.size(); j++){
            if(j != row.size()-1){
                if(!made[i][j] && row[j] == row[j+1]){
                    after.push_back(2*row[j]);
                    made[i][j] = true;
                    made[i][j+1] = true;
                }else if(!made[i][j]){
                    after.push_back(row[j]);
                }
            }else{
                if(!made[i][j])
                    after.push_back(row[j]);
            }
        }
        for(int j = 0; j < after.size(); j++)
            tile2[i][j] = after[j];
        after.clear();
        row.clear();
    }
}
void right(){
    vector<int> row;
    for(int i = 0; i < N; i++){
        for(int j = N-1; j >= 0; j--){
            if(tile[i][j] != 0) row.push_back(tile[i][j]);
        }
        for(int j = 0; j < row.size(); j++){
            if(j != row.size()-1){
                if(!made[i][j] && row[j] == row[j+1]){
                    after.push_back(2*row[j]);
                    made[i][j] = true;
                    made[i][j+1] = true;
                }else if(!made[i][j]){
                    after.push_back(row[j]);
                }
            }else{
                if(!made[i][j])
                    after.push_back(row[j]);
            }
        }
        int _size = N-after.size();
        for(int j = N-1; j >= _size; j--)
            tile2[i][j] = after[N-j-1];
        after.clear();
        row.clear();
    }
}
void up(){
    vector<int> row;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(tile[j][i] != 0) row.push_back(tile[j][i]);
        }
        for(int j = 0; j < row.size(); j++){
            if(j != row.size()-1){
                if(!made[j][i] && row[j] == row[j+1]){
                    after.push_back(2*row[j]);
                    made[j][i] = true;
                    made[j+1][i] = true;
                }else if(!made[j][i]){
                    after.push_back(row[j]);
                }
            }else{
                if(!made[j][i])
                    after.push_back(row[j]);
            }
        }
        for(int j = 0; j < after.size(); j++)
            tile2[j][i] = after[j];
        after.clear();
        row.clear();
    }
}

void down(){
    vector<int> row;
    for(int i = 0; i < N; i++){
        for(int j = N-1; j >= 0; j--){
            if(tile[j][i] != 0) row.push_back(tile[j][i]);
        }
        for(int j = 0; j < row.size(); j++){
            if(j != row.size()-1){
                if(!made[j][i] && row[j] == row[j+1]){
                    after.push_back(2*row[j]);
                    made[j][i] = true;
                    made[j+1][i] = true;
                }else if(!made[j][i]){
                    after.push_back(row[j]);
                }
            }else{
                if(!made[j][i])
                    after.push_back(row[j]);
            }
        }
        int _size = N-after.size();
        for(int j = N-1; j >= _size; j--)
            tile2[j][i] = after[N-j-1];
        after.clear();
        row.clear();
    }
}

int main(int argc, const char * argv[]) {
    int num_case;
    string direction;
    cin >> num_case;
    for(int i = 0; i < num_case; i++){
        cin >> N >> direction;
        for(int k = 0; k < MAX; k++){
            for(int j = 0; j < MAX; j++){
                made[k][j] = false;
                tile[k][j] = 0;
                tile2[k][j] = 0;
            }
        }
        for(int j = 0; j < N; j++){
            for(int k = 0; k < N; k++){
                cin >> tile[j][k];
            }
        }
        if(direction == "left"){
            left();
        }else if(direction == "right"){
            right();
        }else if(direction == "up"){
            up();
        }else if(direction == "down"){
            down();
        }
        cout << "#" << i+1 << endl;
        for(int k = 0; k < N; k++){
            for(int j = 0; j < N; j++){
                if(k == N-1 && j == N-1){
                    cout << tile2[k][j];
                }else{
                    cout << tile2[k][j] << " ";
                }
            }
            cout << endl;
        }
    }
    
    return 0;
}
