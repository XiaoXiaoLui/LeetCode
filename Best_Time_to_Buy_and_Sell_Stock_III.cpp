/******************************************************************************************
Best Time to Buy and Sell Stock III
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
    int maxProfit(vector<int>& a) {
		if (a.size() == 0)
		{
			return 0;
		}
		
		left.resize(a.size());
		right.resize(a.size());
		
		int n = a.size(), i, curMin, curMax, curBest;
		left[0] = right[n - 1] = 0;
		
		curBest = 0;
		curMin = a[0];
		for (i = 1; i < n; i++)
		{
			curBest = max(curBest, a[i] - curMin);
			curMin = min(curMin, a[i]);
			
			left[i] = curBest;
		}
		
		curBest = 0;
		curMax = a[n - 1];
		for (i = n - 2; i >= 0; i--)
		{
			curBest = max(curBest, curMax - a[i]);
			curMax = max(curMax, a[i]);
			
			right[i] = curBest;
		}
		
		int res = right[0];
		for (i = 1; i < n - 2; i++)
		{
			res = max(res, left[i] + right[i + 1]);
		}
		
		return res;
    }
	
	vector<int> left;
	vector<int> right;
};

int main()
{
	Solution S;
	return 0;
}