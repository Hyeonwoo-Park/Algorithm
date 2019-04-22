#include <iostream>
using namespace std;
 
int n, m;
long long pills[31][31];
 
long long sol(int f, int h){
    long long &res = pills[f][h];
    if (f == 0 && h == 0) {
        return 1;
    }
    if (res != 0) return res;
    if (f != 0) res += sol(f - 1, h + 1);
    if (h != 0) res += sol(f, h - 1);
    return res;
}
 
int main(void) {
    int n;
    while (cin >> n){
        if (n == 0) break;
        else
            cout << sol(n, 0) << '\n';
    }
}
