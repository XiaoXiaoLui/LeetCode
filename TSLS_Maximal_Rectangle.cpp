/******************************************************************************************
Maximal Rectangle
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
    int maximalRectangle(vector<vector<char> >& matrix) {
		if (matrix.size() == 0)
		{
			return 0;
		}
		int i, j, ii, jj;
        n = matrix.size();
		m = matrix[0].size();
		sum.resize(n + 2);
		for (i = 0; i <= n; i++)
		{
			sum[i].resize(m + 2);
		}
		
		
		for (j = 0; j <= m; j++)
		{
			sum[0][j] = 0;
		}
		for (i = 0; i <= n; i++)
		{
			sum[i][0] = 0;
		}
		
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= m; j++)
			{
				sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
				if (matrix[i - 1][j - 1] == '1')
				{
					sum[i][j]++;
				}
			}
		}
		
		int ans = 0, tmp;
		for (i = 1; i <= n; i++)
		{
			for (ii = i; ii <= n; ii++)
			{
				for (j = jj = 1; jj <= m;)
				{		
					tmp = sum[ii][jj] - sum[i - 1][jj] - sum[ii][j - 1] + sum[i - 1][j - 1];
					if (tmp == (ii - i + 1) * (jj - j + 1))
					{
						ans = max(ans, tmp);
						jj++;
					}
					else
					{
						j = ++jj;
					}						
				}
			}
		}	
		
		return ans;
    }
	
	vector<vector<int> > sum;
	int n, m;
};

int main()
{
	
	vector<vector<char> > mat;
	string str[4] = {"10100","10111","11111","10010"};
	Solution S;
	return 0;
}