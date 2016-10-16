/******************************************************************************************
Edit Distance
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
    int minDistance(string word1, string word2) {
        dp.clear();
		
		return solve(word1, word2, 0, 0);
    }
	
	int solve(const string &s1, const string &s2, int i, int j)
	{
		if (i >= s1.size())
		{
			return s2.size() - j;
		}
		if (j >= s2.size())
		{
			return s1.size() - i;
		}
		
		map<pii, int>::iterator iter;
		if ((iter = dp.find(mp(i, j))) != dp.end())
		{
			return iter->second;
		}
		
		int res = 0;
		if (s1[i] == s2[j])
		{
			res = solve(s1, s2, i + 1, j + 1);
		}
		else
		{
			res = solve(s1, s2, i + 1, j + 1) + 1; // modify
			res = min(res, solve(s1, s2, i, j + 1) + 1); // insert
			res = min(res, solve(s1, s2, i + 1, j) + 1); // erase
		}
		
		dp[mp(i, j)] = res;
		return res;
	}
	
	map<pii, int> dp;
};

int main()
{
	Solution S;
	return 0;
}