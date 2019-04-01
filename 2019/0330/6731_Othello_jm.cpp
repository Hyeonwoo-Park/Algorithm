#include <iostream>
 
using namespace std;
 
int main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin >> t;
 
    for (int tc = 1; tc <= t; tc++)
    {
        int ans = 0;
        char board[1000][1000];
        int h[1000] = { 0, };
        int v[1000] = { 0, };
 
        int n;
        cin >> n;
 
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> board[i][j];
                if (board[i][j] == 'B')
                {
                    h[i]++;
                    v[j]++;
                }
            }
        }
 
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int x = h[i] + v[j];
                if (board[i][j] == 'B')
                    x -= 1;
 
                if (x % 2 != 0)
                    ans++;
            }
        }
        cout << '#' << tc << ' ' << ans << '\n';
    }
    return 0;
}
