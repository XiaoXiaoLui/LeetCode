/******************************************************************************************
Max Sum of Rectangle No Larger Than K
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
    int maxSumSubmatrix(vector<vector<int> >& matrix, int maxK) {
		if (matrix.size() == 0)
		{
			return 0;
		}
		
		int i, j, k, n, m, curSum;
		n = matrix.size();
		m = matrix[0].size();
		vector<vector<int> > a;
		
		if (n > 10*m)
		{
			a.resize(m);
			for (i = 0; i < m; i++)
			{
				a[i].resize(n);
				for (j = 0; j < n; j++)
				{
					a[i][j] = matrix[j][i];
				}
			}
			swap(n, m);
		}
		else
		{
			a = matrix;
		}
		
        vector<vector<int> > sum(n);
		vector<vector<int> > rowSum(n);
		set<int> S;
		
		int ans = -2e9;
		for (i = 0; i < n; i++)
		{
			sum[i].insert(sum[i].end(), m, 0);
			curSum = 0;
			for (j = 0; j < m; j++)
			{
				curSum += a[i][j];
				rowSum[i].push_back(curSum);
			}
		}
		
		for (k = 0; k < n; k++)
		{
			for (i = 0; i + k < n; i++)
			{
				curSum = 0;
				S.clear();
				S.insert(0);
				for (j = 0; j < m; j++)
				{
					curSum = sum[i][j] + rowSum[i + k][j];
					sum[i][j] = curSum;
					auto iter = S.lower_bound(curSum - maxK);
					if (iter != S.end())
					{
						ans = max(ans, curSum - *iter);
					}
					S.insert(curSum);
				}
			}
		}
		
		return ans;
    }
};


int main()
{
	Solution S;
	return 0;
}