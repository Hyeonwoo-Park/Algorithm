#include<iostream>
#include<deque>
#include<vector>
#include<algorithm>
using namespace std;
 
int main()
{
    int t;
    cin >> t;
 
    for (int test = 1; test <= t; test++)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        deque<int> dq;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
 
        sort(v.begin(), v.end());
 
        for (int i = 0; i < n; i++)
        {
            if (i == 0)
            {
                dq.push_front(v[i]);
            }
            else
            {
                if (i % 2 == 1)
                {
                    dq.push_front(v[i]);
                }
                else
                {
                    dq.push_back(v[i]);
                }
            }
        }
 
        int minimum = 0;
        for (int i = 0; i < n; i++)
        {
            if (i == n - 1)
            {
                if(minimum<abs(dq[i] - dq[0]))
                minimum = abs(dq[i] - dq[0]);
            }
            else
            {
                if(minimum < abs(dq[i] - dq[i+1]))
                   minimum = abs(dq[i] - dq[i+1]);
            }
        }
 
 
        cout << '#' << test << ' ' << minimum << "\n";
    }
 
    return 0;
}
