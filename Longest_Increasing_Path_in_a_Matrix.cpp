/******************************************************************************************
Longest Increasing Path in a Matrix
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

const static int DIR[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
		if (!matrix.size())
		{
			return 0;
		}
		
		int i, j, nextI, nextJ, k, num;
		n = matrix.size();
		m = matrix[0].size();
        vector<vector<int> > dp(n);
		for (i = 0; i < n; i++)
		{
			dp[i].insert(dp[i].end(), m, 1);
		}
		
		vector<pair<int, pii> > srt;
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
			{
				srt.push_back(make_pair(matrix[i][j], mp(i, j)));
			}
		}
		
		sort(srt.begin(), srt.end(), greater<pair<int, pii> >());
		
		int ans = 1;
		for (auto &tmp : srt)
		{
			i = tmp.second.first;
			j = tmp.second.second;
			num = tmp.first;
			for (k = 0; k < 4; k++)
			{
				nextI = i + DIR[k][0];
				nextJ = j + DIR[k][1];
				if (isValid(nextI, nextJ) && matrix[nextI][nextJ] > num)
				{
					dp[i][j] = max(dp[i][j], dp[nextI][nextJ] + 1);
				}
			}
			ans = max(ans, dp[i][j]);
		}
		
		return ans;
    }
	
	bool isValid(int row, int col)
	{
		return row >= 0 && row < n && col >= 0 && col < m;
	}
	
	int n, m;
};

int main()
{
	vector<vector<int> > a = {
		{3,4,5},
		{3,2,6},
		{2,2,1}};
	Solution S;
	
	cout << S.longestIncreasingPath(a) << endl;
	return 0;
}