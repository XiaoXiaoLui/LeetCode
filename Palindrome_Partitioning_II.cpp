/******************************************************************************************
Palindrome Partitioning II
******************************************************************************************/


#include<bits/stdc++.h>

using namespace std;

#define pii pair<int, int>
#define mp make_pair

typedef long long ll;

class Solution {
public:
    int minCut(string s) {
		int n = s.size();
		if (!n)
		{
			return 0;
		}
		
		int i, res, left, right, l, r, curBest;
        vector<int> dp(n, -1);
		vector<vector<int> > palidLeft(n); // palidLeft[right] records left side of palidrome ends at right
		
		for (i = 0; i < 2*n - 1; i++)
		{
			if (i % 2 == 0)
			{
				palidLeft[i / 2].push_back(i / 2);
			}
			
			for (l = i - 1, r = i + 1; l >= 0 && r < 2*n - 1; l -= 2, r += 2)
			{
				left = l / 2;
				right = (r + 1) / 2;
				if (s[left] != s[right])
				{
					break;
				}
				
				palidLeft[right].push_back(left);
				if (left == 0)
				{
					dp[right] = 0;
					break;
				}
			}
		}
		
		dp[0] = 0;
		for (i = 1; i < n; i++)
		{
			if (dp[i] == 0)
			{
				continue;
			}
			curBest = 1e9;
			for (auto e : palidLeft[i])
			{
				curBest = min(curBest, dp[e - 1] + 1);
			}
			dp[i] = curBest;
		}
		
		return dp[n - 1];
    }	
};


int main()
{
	Solution S;
	return 0;
}