/******************************************************************************************
Best Time to Buy and Sell Stock II
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
		int n = a.size();
		int res = 0;
		int i, j;
		for (i = 0; i < n - 1; i = j)
		{
			for (j = i + 1; j < n && a[j] >= a[j - 1]; j++);
			
			if (j - 1 > i)
			{
				res += a[j - 1] - a[i];
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