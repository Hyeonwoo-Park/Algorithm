#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n;
int d[21][21];
vector <int> v[21];
int nd[21][21];

void left()
{
	for(int i = 0; i < n; i ++)
		for (int j = 0; j < n; j++)
		{
			if (d[i][j] != 0)
				v[i].push_back(d[i][j]);
		}

	for (int i = 0; i < n; i++)
	{
		int y = 0;// j = vector에서 참조할 인덱스
		for (int j = 0; j < v[i].size(); j++)
		{
			if (j + 1 < v[i].size() && v[i][j] == v[i][j + 1])
			{
				nd[i][y] = 2 * v[i][j];
				j++;
				y++;
			}
			else
			{
				nd[i][y] = v[i][j];
				y++;
			}
		}
	}
	return;
}
void right()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			if (d[i][j] != 0)
				v[i].push_back(d[i][j]);
		}

	for (int i = 0; i < n; i++)
	{
		int y = n - 1;
		for (int j = v[i].size() - 1 ; j >= 0; j--)
		{
			if (j - 1 >= 0 && v[i][j] == v[i][j - 1])
			{
				nd[i][y] = 2 * v[i][j];
				j--;
				y--;
			}
			else
			{
				nd[i][y] = v[i][j];
				y--;
			}
		}
	}
	return;
}
void up()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			if (d[i][j] != 0)
				v[j].push_back(d[i][j]);
		}

	for (int i = 0; i < n; i++)
	{
		int x = 0;
		for (int j = 0; j < v[i].size(); j++)
		{
			if (j + 1 < v[i].size() && v[i][j] == v[i][j + 1])
			{
				nd[x][i] = 2 * v[i][j];
				j++;
				x++;
			}
			else
			{
				nd[x][i] = v[i][j];
				x++;
			}
		}
	}
	return;
}
void down()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			if (d[i][j] != 0)
				v[j].push_back(d[i][j]);
		}

	for (int i = 0; i < n; i++)
	{
		int x = n - 1;
		for (int j = v[i].size() - 1; j >= 0; j--)
		{
			if (j - 1 >= 0 && v[i][j] == v[i][j - 1])
			{
				nd[x][i] = 2 * v[i][j];
				j--;
				x--;
			}
			else
			{
				nd[x][i] = v[i][j];
				x--;
			}
		}
	}
	return;
}

int main(){

	int t;
	cin >> t;

	for (int test = 1; test <= t; test++)
	{
		cin >> n;
		string s;
		cin >> s;

		for (int i = 0; i < n; i++)
		{
			v[i].clear();
			for (int j = 0; j < n; j++)
			{
				cin >> d[i][j];
				nd[i][j] = 0;
			}
		}

		if (s == "left")
			left();
		else if (s == "right")
			right();
		else if (s == "up")
			up();
		else if (s == "down")
			down();

		cout << '#' << test << '\n';
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cout << nd[i][j] << ' ';
			}
			cout << '\n';
		}
	}

	return 0;
}
