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
#include <stack>
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
		
		int res = 0, i, j, m, n;
		n = matrix.size();
		m = matrix[0].size();
		vector<vector<int> > h(n + 1);
		h[n].insert(h[n].begin(), m + 1, 0);
		
		for (i = n - 1; i >= 0; i--)
		{
			h[i].resize(m + 1);
			for (j = 0; j < m; j++)
			{
				if (matrix[i][j] == '1')
				{
					h[i][j] = h[i + 1][j] + 1;
				}
				else
				{
					h[i][j] = 0;
				}
			}
			h[i][m] = 0;
		
			stack<int> S;
			for (j = 0; j <= m;)
			{
				if (S.empty() || h[i][j] >= h[i][S.top()])
				{
					S.push(j);
					j++;
				}
				else
				{
					int tmp = S.top();
					S.pop();
					res = max(res, h[i][tmp] * (S.empty() ? j : j - S.top() - 1));
				}
			}
		}
		return res;
    }
	
	
};

int main()
{
	
	vector<vector<char> > mat;
	string str[4] = {"10100","10111","11111","10010"};
	Solution S;
	return 0;
}