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

class FenWickTree
{
public:
	FenWickTree(int n)
	{
		tr = new int[n + 10];
		this->n = n;
		for (int i = 0; i < n + 10; i++)
		{
			tr[i] = (int)1e9;
		}
	}
	
	void update(int i, int value)
	{
		while (i <= n)
		{
			tr[i] = min(tr[i], value);
			i += lowbit(i);
		}
	}
	
	int query(int i)
	{
		int res = (int)1e9;
		while (i)
		{
			res = min(res, tr[i]);
			i -= lowbit(i);
		}
		return res;
	}
	
	int lowbit(int a)
	{
		return a & (-a);
	}
	
private:
	int *tr;
	int n;
};

class Solution {
public:
    int jump(vector<int>& nums) {
		dp = new int[nums.size()];
		FenWickTree ft(nums.size());
		
        int i;
		dp[nums.size() - 1] = 0;
		ft.update(nums.size(), 0);
		for (i = nums.size() - 2; i >= 0; i--)
		{
			dp[i] = ft.query(min((int)nums.size(), i + nums[i] + 1)) + 1;
			ft.update(i + 1, dp[i]);
		}
		
		return dp[0];
    }
	
	int *dp;
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