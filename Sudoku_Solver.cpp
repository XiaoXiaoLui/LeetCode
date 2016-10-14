/******************************************************************************************
Sudoku Solver
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


void genRandom(vector<int>& a, int n, int low, int high)
{
	srand(time(0));
	for (int i = 0; i < n; i++)
	{
		a.push_back(rand() % (high - low) + low);
	}
}

void print(vector<int> &a)
{
	for (int i = 0; i < a.size(); i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

#define pii pair<int, int>
#define mp make_pair

typedef long long ll;

class Solution {
public:
    void solveSudoku(vector<vector<char> >& board) {
        int i, j, digit;
		memset(a, 0, sizeof(a));
		memset(row, 0, sizeof(row));
		memset(col, 0, sizeof(col));
		memset(block, 0, sizeof(block));
		
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= n; j++)
			{
				if (board[i - 1][j - 1] != '.')
				{
					digit = board[i - 1][j - 1] - '0';
					a[i][j] = digit;
					row[i][digit] = true;
					col[j][digit] = true;
					block[blockIdx(i, j)][digit] = true;
				}
			}
		}
		
		bool res = solve(1, 1);
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= n; j++)
			{
				board[i - 1][j - 1] = char(a[i][j] + '0');
			}
		}
		
		//return res;
    }
	
	bool solve(int i, int j)
	{
		int digit;
		if (i > n)
		{
			return true;
		}
		
		pii pos = nextPos(i, j);
		
		if (a[i][j])
		{
			return solve(pos.first, pos.second);
		}
		
		for (digit = 1; digit <= n; digit++)
		{
			if (row[i][digit] || col[j][digit] || block[blockIdx(i, j)][digit])
			{
				continue;
			}
			a[i][j] = digit;
			row[i][digit] = true;
			col[j][digit] = true;
			block[blockIdx(i, j)][digit] = true;
			
			if (solve(pos.first, pos.second))
			{
				return true;
			}
			
			a[i][j] = 0;
			row[i][digit] = false;
			col[j][digit] = false;
			block[blockIdx(i, j)][digit] = false;
		}
		
		return false;
	}

	pii nextPos(int row, int col)
	{
		int i, j;
		i = row;
		j = col + 1;
		if (j > n)
		{
			i++;
			j = 1;
		}
		return mp(i, j);
	}
	
	int blockIdx(int i, int j)
	{
		i = (i - 1) / 3;
		j = (j - 1) / 3;
		return 3*i + j + 1;
	}
	
	const static int n = 9;
	const static int N = 11;
	bool row[N][N];
	bool col[N][N];
	bool block[N][N];
	int a[N][N];
};

int main()
{
	char a[11][11] = {"..9748...","7........",".2.1.9...","..7...24.",".64.1.59.",".98...3..","...8.3.2.","........6","...2759.."};
	vector<vector<char> > bd;
	bd.resize(15);
	int i, j;
	for (i = 1; i <= 9; i++)
	{
		bd[i - 1].resize(15);
		for (j = 1; j <= 9; j++)
		{
			bd[i - 1][j - 1] = a[i - 1][j - 1];
		}
	}
	
	Solution S;
	S.solveSudoku(bd);
	//printf("%d\n", res);
	for (i = 1; i <= 9;  i++)
	{
		for (j = 1; j <= 9; j++)
		{
			printf("%c", bd[i - 1][j - 1]);
		}
		printf("\n");
	}
	return 0;
}