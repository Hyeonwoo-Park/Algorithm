//
//  main.cpp
//  1486_HighShelf
//
//  Created by 잉뿌 on 27/03/2019.
//  Copyright © 2019 잉뿌. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <math.h>
#define MAX 1100000

using namespace std;

int B;  //선반 높이
int N;  //점원 수
int H[21];  //점원 키 정보. N<=20. H[0]은 안쓰려고
int minimum_height=100001;

int d[21][MAX];

int main(int argc, const char * argv[]) {
    
    cout << "START\n";
    
    int T;
    cin >> T;
    
    for(int i=1 ; i<=T ; i++){
    cin >> N >> B;
    for(int i=1 ; i<=N ; i++){
        cin >> H[i];
        if(H[i]<minimum_height) minimum_height=H[i];
    }
    
    if(B<minimum_height){
        cout << minimum_height-B << '\n';
        return 0;
    }
    
    
    d[0][0]=0;
    
    for(int i=1; i<=N ; i++){
        for(int j=0; j< pow(2.0,i-1) ; j++){
            d[i][j]=d[i-1][j];
        }
        for(int j=pow(2.0,i-1) ; j<=pow(2.0,i) ; j++){
            d[i][j]=d[i-1][j-(int)pow(2.0,i-1)]+H[i];
        }
    }
    
    int ans = 0;
    
    for(int j=0 ; j<pow(2.0,N) ; j++){
        if(d[N][j]>=B && abs(B-d[N][j])<abs(B-ans))
            ans = d[N][j];
    }
    
        
    cout << "ans=" << ans << '\n';
    cout << abs(B-ans) << '\n';
        
    cout << "#" << i << " " << abs(B-ans) << '\n';
    

    }
    
    cout << "THE END\n";
    
    return 0;
}
