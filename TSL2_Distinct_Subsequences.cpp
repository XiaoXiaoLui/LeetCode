/******************************************************************************************
Distinct Subsequences
******************************************************************************************/


#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstring>
#include <queue>
#include <ctime>

using namespace std;

#define pii pair<int, int>
#define mp make_pair

typedef long long ll;

class Solution {
public:
    int numDistinct(string s, string t) {
		dp.clear();
		dp.resize(s.size());
		for (int i = 0; i < s.size(); i++)
		{
			dp[i].clear();
			dp[i].insert(dp[i].begin(), t.size(), -1);
		}
		
		return solve(s, t, 0, 0);
    }
	
	int solve(const string &s, const string &t, int i, int j)
	{
		if (j >= t.size())
		{
			return 1;
		}
		if (t.size() - j > s.size() - i)
		{
			return 0;
		}
		
		if (dp[i][j] != -1)
		{
			return dp[i][j];
		}
		
		int res = 0;
		
		if (s[i] == t[j])
		{
			res += solve(s, t, i + 1, j + 1);
		}
		res += solve(s, t, i + 1, j);
		
		
		dp[i][j] = res;
		return res;
	}
	
	vector<vector<int> > dp;
};

int main()
{
	string a = "aaa";
	string b = "aa";
	Solution S;
	cout << S.numDistinct(a, b) << endl;
	return 0;
}