/******************************************************************************************
Longest Valid Parentheses
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
    int longestValidParentheses(string s) {
        int res = 0;
		int i, start, sum;
		for (sum = 0, start = 0, i = 0; i < s.size(); i++)
		{
			if (s[i] == '(')
			{
				sum++;
			}
			else
			{
				sum--;
			}
			
			if (sum == 0)
			{
				res = max(res, i - start + 1);
			}
			else if (sum < 0)
			{
				start = i + 1;
				sum = 0;
			}
		}
		
		for (sum = 0, start = i = s.size() - 1; i >= 0; i--)
		{
			if (s[i] == '(')
			{
				sum--;
			}
			else
			{
				sum++;
			}
			
			if (sum == 0)
			{
				res = max(res, start - i + 1);
			}
			else if (sum < 0)
			{
				start = i - 1;
				sum = 0;
			}
		}
		
		return res;
    }
};

int main()
{
	Solution S;
	return 0;
}