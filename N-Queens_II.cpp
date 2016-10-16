/******************************************************************************************
N-Queens II
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
    int totalNQueens(int nn) {
        n = nn;
		memset(col, 0, sizeof(col));
		memset(diag1, 0, sizeof(diag1));
		memset(diag2, 0, sizeof(diag2));
		count = 0;
		
		for (int i = 0; i < n; i++)
		{
			a[i].append(n, '.');
		}
		
		solve(0);
		
		return count;
    }
	
	void solve(int i)
	{
		if (i == n)
		{
			count++;
			return;
		}
		
		int j;
		for (j = 0; j < n; j++)
		{
			if (col[j] || diag1[i + j] || diag2[i - j + n])
			{
				continue;
			}
			a[i][j] = 'Q';
			col[j] = true;
			diag1[i + j] = true;
			diag2[i - j + n] = true;
			
			solve(i + 1);
			a[i][j] = '.';
			col[j] = false;
			diag1[i + j] = false;
			diag2[i - j + n] = false;
		}
	}
	
	int n;
	const int static  N = 30;
	string a[N];
	bool col[N];
	bool diag1[2*N];
	bool diag2[2*N];
	int count;
	//vector<vector<string> > res;
};

int main()
{
	Solution S;
	int count = S.totalNQueens(8);
	printf("%d\n", count);
	return 0;
}