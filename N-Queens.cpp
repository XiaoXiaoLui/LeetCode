/******************************************************************************************
N-Queens
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
    vector<vector<string> > solveNQueens(int nn) {
        n = nn;
		memset(col, 0, sizeof(col));
		memset(diag1, 0, sizeof(diag1));
		memset(diag2, 0, sizeof(diag2));
		res.clear();
		for (int i = 0; i < n; i++)
		{
			a[i].append(n, '.');
		}
		
		solve(0);
		
		return res;
    }
	
	void solve(int i)
	{
		if (i == n)
		{
			print();
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

	void print()
	{
		vector<string> curVec;
		for (int i = 0; i < n; i++)
		{
			curVec.push_back(a[i]);
		}
		res.push_back(curVec);
	}
	
	int n;
	const int static  N = 30;
	string a[N];
	bool col[N];
	bool diag1[2*N];
	bool diag2[2*N];
	vector<vector<string> > res;
};

int main()
{
	Solution S;
	vector<vector<string> > vec = S.solveNQueens(8);
	for (int i = 0; i < vec.size(); i++)
	{
		for (int j = 0; j < vec[i].size(); j++)
		{
			printf("%s\n", vec[i][j].c_str());
		}
		printf("\n");
	}
	return 0;
}