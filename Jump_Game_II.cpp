/******************************************************************************************
Jump Game II
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
    int jump(vector<int>& a) {
		vector<int> cash;
		int n = a.size() - 1, i, j, cur;
		
		vector<int> dp(n + 1);
		dp[n] = 0;
		cash.push_back(n);
		
        for (i = n - 1; i >= 0; i--)
		{
			while (cash.size() > 1 && cash[cash.size() - 2] <= i + a[i])
			{
				cash.pop_back();
			}
			dp[i] = dp[cash.back()] + 1;
			cash.push_back(i);
		}
		
		return dp[0];
    }
	
};

int main()
{
	vector<int> a;
	a.push_back(1);
	a.push_back(2);
	Solution S;
	printf("%d\n", S.jump(a));
	return 0;
}