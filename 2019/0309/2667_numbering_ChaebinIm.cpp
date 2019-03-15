//
//  main.cpp
//  AlgorithmStudy_7
//
//  Created by 임채빈 on 15/03/2019.
//  Copyright © 2019 임채빈. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;
//There are two matrixes that one means whether it was already checked, and another means that there is someone living.
bool check[30][30];
//'n' is the size of area, num means each size of the groups.
//'cnt'(count) means the number of the groups.
int n, arr[30][30],num[1010],cnt;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

void dfs(int x,int y) {
    //we want to check the address that is arr[x][y]
    check[x][y] = true;
    //we want to add 1 to the population of the group.
    num[cnt]++;
    //we want to check the 4 near neighbors from the address.(right, left, up, down)
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        //the condition means the index is out of range (it is really important)
        if (0 <= nx && nx < n && 0 <= ny && ny < n) {
            //if the adjacent area had not yet checked and the component is not zero, let's implement the dfs.
            if (!check[nx][ny] &&arr[nx][ny])
                dfs(nx, ny);
        }
    }
}
int main() {
    // the number of inputs
    cin >> n;
    // assign the inputs
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf(" %1d", &arr[i][j]);
        }
    }
    
    // implement DFS
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // check the component whether it is already checked and is not zero
            if (!check[i][j] && arr[i][j]){
                dfs(i, j);
                //here, the cnt(count) means the number of groups.
                cnt++;
            }
        }
    }
    
    
    cout << cnt << endl;
    sort(num, num + cnt);
    for (int i = 0; i < cnt; i++)
        cout << num[i] << endl;
}


/*
int maxOfMatrix(int matrix[MAXSIZE][MAXSIZE], int i, int j){
    return max(matrix[i][j-1], max(matrix[i-1][j], max(matrix[i+1][j], matrix[i][j+1])));
}

int main(int argc, const char * argv[]) {
    //input number
    int n;
    cout << "let's input" << endl;
    cin >> n;
    //create address matrix : its size is bigger than original matrix. (amount:2, which is the frame of the matrix)
    int address[MAXSIZE][MAXSIZE];
    //at the frame of the matrix, the value '0' is assigned
    for(int i = 0; i < n+2; i++){
        address[0][i] = 0;
        address[i][0] = 0;
        address[n+1][i] = 0;
        address[i][n+1] = 0;
    }
    //input the existance of address.
    for(int i = 1; i < n+1; i++){
        for(int j = 1; j < n+1; j++){
            cin >> address[i][j];
        }
    }
    cout << "input is all taken." << endl;
    //check is the # of group of the neighbors.
    int check = 1;
    
    //it is the output of the print of this problem.
    int addressSize[26];
    for(int i = 0; i < 26; i++)
        addressSize[i] = 0;
    // check the neighbors
    for(int i = 1; i < n+1; i++){
        for(int j = 1; j < n+1; j++){
            if(address[i][j] == 1 && maxOfMatrix(address, i, j) <= 1){
                check++;
                addressSize[check]++;
                address[i][j] = check;
                if(address[i+1][j] == 1 && address[i][j-1] == 0 && address[i+1][j-1] == 1){
                    address[i+1][j-1] = address[i][j];
                    addressSize[address[i][j]]++;
                }
            }else if(address[i][j] == 1 && maxOfMatrix(address, i, j) > 1){
                address[i][j] = maxOfMatrix(address, i, j);
                addressSize[maxOfMatrix(address,i,j)]++;
                if(address[i+1][j] == 1 && address[i][j-1] == 0 && address[i+1][j-1] == 1){
                    address[i+1][j-1] = address[i][j];
                    addressSize[address[i][j]]++;
                }
            }
        }
    }
    cout << check-1 << endl;
    for(int i = 2; i <= check+1; i++){
        cout << addressSize[i] << endl;
    }
    
    
    return 0;
}
*/
