/******************************************************************************************
Burst Balloons
******************************************************************************************/

#include<bits/stdc++.h>

using namespace std;

#define pii pair<int, int>
#define mp make_pair
#define INIT_UNORDER(mm) \
{\
	mm.max_load_factor(0.25);\
	mm.reserve(512);\
}

typedef long long ll;

class Solution {
public:
    int maxCoins(vector<int>& nums) {
		int n = nums.size();
        vector<int> a(n + 3);
		vector<vector<int> > dp(n + 3);
		int i, j, k;
		for (i = 1; i <= n; i++)
		{
			a[i] = nums[i - 1];
			dp[i].insert(dp[i].end(), n + 2, 0);
		}
		a[0] = a[n + 1] = 1;
		dp[0].insert(dp[0].end(), n + 2, 0);
		dp[n + 1].insert(dp[n + 1].end(), n + 2, 0);
		
		for (k = 2; k <= n + 1; k++)
		{
			for (i = 0; i + k <= n + 1 ; i++)
			{
				for (j = i + 1; j < i + k; j++)
				{
					dp[i][i + k] = max(dp[i][i + k], dp[i][j] + dp[j][i + k] + a[i] * a[j] * a[i + k]);
				}
			}
		}
		
		return dp[0][n + 1];
    }
};


int main()
{
	Solution S;
	vector<int> a{9,76,64,21,97};
	int ans = S.maxCoins(a);
	cout << ans << endl;
	return 0;
}

/*
a*b*left + b*left*right
a*left*right + a*b*right
a*b*(left - right) + left*right(a - b)
*/