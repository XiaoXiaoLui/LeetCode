/******************************************************************************************
Interleaving String
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
    bool isInterleave(string s1, string s2, string s3) {
        if (s3.size() != s1.size() + s2.size())
		{
			return false;
		}
		
		dp.clear();
		return solve(s1, s2, s3, 0, 0);
    }
	
	bool solve(const string &s1, const string &s2, const string &s3, int i, int j)
	{
		if (i + j == s3.size())
		{
			return true;
		}
		
		map<pii, bool>::iterator iter;
		if ((iter = dp.find(mp(i, j))) != dp.end())
		{
			return iter->second;
		}
		
		if (i < s1.size() && s3[i + j] == s1[i])
		{
			if (solve(s1, s2, s3, i + 1, j))
			{
				return true;
			}
		}
		
		if (j < s2.size() && s3[i + j] == s2[j])
		{
			if (solve(s1, s2, s3, i, j + 1))
			{
				return true;
			}
		}
		
		dp[mp(i, j)] = false;
		return false;
	}
	
	map<pii, bool> dp;
};

int main()
{
	Solution S;
	return 0;
}