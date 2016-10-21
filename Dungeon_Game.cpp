/******************************************************************************************
Dungeon Game
******************************************************************************************/

#include<bits/stdc++.h>

using namespace std;

#define pii pair<int, int>
#define mp make_pair
#define INIT_UNORDER(mm) \
{\
	mm.max_load_factor(0.25);\
	mm.reserve(512);\
}\

typedef long long ll;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& a) {
		int n = a.size();
		int m = a[0].size();
        vector<vector<int> > dp(n);
		int i, j;
		for (i = 0; i < n; i++)
		{
			dp[i].resize(m);
		}
		
		dp[n - 1][m - 1] = max(1, 1 - a[n - 1][m - 1]);
		for (i = n - 2; i >= 0; i--)
		{
			dp[i][m - 1] = max(1, dp[i + 1][m - 1] - a[i][m - 1]);
		}
		for (j = m - 2; j >= 0; j--)
		{
			dp[n - 1][j] = max(1, dp[n - 1][j + 1] - a[n - 1][j]);
		}
		
		for (i = n - 2; i >= 0; i--)
		{
			for (j = m - 2; j >= 0; j--)
			{
				int tmp = min(dp[i + 1][j], dp[i][j + 1]);
				dp[i][j] = max(1, tmp - a[i][j]);
			}
		}
		
		return dp[0][0];
    }
};

int main()
{
	Solution S;
	return 0;
}