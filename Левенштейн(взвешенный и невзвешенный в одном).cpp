#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

int lev(string f, string s, int repl = 1, int del = 1, int add = 1)
{
	vector <vector <int>> fnc(f.size() + 1, vector <int>(s.size() + 1));
	fnc[0][0] = 0;

	for (int i = 1; i <= f.size(); i++)
	{
		fnc[i][0] = fnc[i- 1][0] + del;
	}

	for (int i = 1; i <= s.size(); i++)
	{
		fnc[0][i] = fnc[0][i - 1] + add;
	}

	for (int i = 1; i <= f.size(); i++)
	{
		for (int j = 1; j <= s.size(); j++)
		{
			fnc[i][j] = min(fnc[i - 1][j - 1] + int(f[i - 1] != s[j - 1]) * repl, min(fnc[i - 1][j] + del, fnc[i][j - 1] + add));
		}
	}
	return fnc[f.size()][s.size()];
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string f, s;
	cin >> f >> s;

	cout << lev(f, s, 12, 20, 15);
}
