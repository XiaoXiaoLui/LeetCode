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
	Solution() : dpN(0), dpM(0), dp(0)
	{
		
	}
	~Solution()
	{
		if (!dp)
		{
			return;
		}
		
		for (int i = 0; i < dpN; i++)
		{
			delete []dp[i];
		}
		delete []dp;
	}
	
    int minDistance(string word1, string word2) {
		int n, m, i;
		n = word1.size();
		m = word2.size();
        
		if (n > dpN || m > dpM)
		{
			if (dp)
			{
				for (int i = 0; i < dpN; i++)
				{
					delete []dp[i];
				}
				delete []dp;
			}
			dpN = n;
			dpM = m;
			
			dp = new int*[dpN];
			for (i = 0; i < dpN; i++)
			{
				dp[i] = new int[dpM];
			}
		}
		
		for (i = 0; i < dpN; i++)
		{
			memset(dp[i], 0xff, dpM * sizeof(int));
		}
		int res = solve(word1, word2, 0, 0);
		return res;
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
		
		if (dp[i][j] >= 0)
		{
			return dp[i][j];
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
		
		dp[i][j] = res;
		return res;
	}
	
	//map<pii, int> dp;
	int **dp;
	int dpN;
	int dpM;
};

int main()
{
	string a = "a";
	string b = "b";
	Solution S;
	S.minDistance(a, b);
	return 0;
}