#include<iostream>
#include<string>
#include<stack>
using namespace std;
int main(void) {

	string stick;
	cin >> stick;

	stack<int> s;
	int ans = 0;
	for (int i = 0; i < stick.size(); i++)
	{
		if (stick[i] == '(')
			s.push(i);
		else
		{
			if (s.top() + 1 == i)
			{
				s.pop();
				ans += s.size();
			}
			else
			{
				s.pop();
				ans++;
			}
		}
	}

	cout << ans << endl;
	return 0;
}
