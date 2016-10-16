/******************************************************************************************
Scramble String
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

#define triple pair<pii, int>
#define mt(a, b, c) mp(mp(a, b), c)

typedef long long ll;

class Solution {
public:
    bool isScramble(string s1, string s2) {
		if (s1.size() != s2.size())
		{
			return false;
		}
		if (s1.size() == 0)
		{
			return true;
		}
		dp.clear();
		return solve(s1, s2, 0, 0, s1.size());
    }
	
	bool solve(const string &s1, const string &s2, int i, int j, int len)
	{
		if (len == 1)
		{
			return s1[i] == s2[j];
		}
		
		map<triple, bool>::iterator iter;
		if ((iter = dp.find(mt(i, j, len))) != dp.end())
		{
			return iter->second;
		}
		
		int len1, len2;
		bool res = false;
		for (len1 = 1; len1 < len; len1++)
		{
			len2 = len - len1;
			if (solve(s1, s2, i, j, len1) && solve(s1, s2, i + len1, j + len1, len2))
			{
				res = true;
				break;
			}
			if (solve(s1, s2, i, j + len2, len1) && solve(s1, s2, i + len1, j, len2))
			{
				res = true;
				break;
			}
		}
		
		dp[mt(i, j, len)] = res;
		return res;
	}
	
	map<triple, bool> dp;
};

int main()
{
	string a = "abb";
	string b = "bab";
	Solution S;
	
	cout << S.isScramble(a, b) << endl;
	return 0;
}