/******************************************************************************************
Frog Jump
******************************************************************************************/

#include<bits/stdc++.h>

using namespace std;

#define pii pair<int, int>
#define mp make_pair
#define INIT_UNORDER(mm) \
{\
	mm.max_load_factor(0.25);\
	mm.reserve(512);\
}

typedef long long ll;

// use unordered_map
class Solution {
public:
	struct MyHash
	{
		size_t operator () (const pii &p) const
		{
			return obj((ll)p.first << 32 + p.second);
		}
		
		hash<ll> obj;
	};
	
    bool canCross(vector<int>& stones) {
		int n = stones.size();
		if (n <= 1)
		{
			return true;
		}
		if (stones[1] != 1)
		{
			return false;
		}
		
        unordered_set<pii, MyHash> dp;
		
		return dfs(stones, 1, 1, dp);
    }
	
	bool dfs(const vector<int> &a, int pos, int preJump, unordered_set<pii, MyHash> &dp)
	{
		if (dp.count(mp(pos, preJump)))
		{
			return false;
		}
			
		if (pos == a.size() - 1)
		{
			return true;
		}
		
		int nextJump;
		vector<int>::const_iterator iter;
		if (preJump > 1)
		{
			nextJump = preJump - 1;
			iter = lower_bound(a.begin() + pos, a.end(), a[pos] + nextJump);
			if (iter != a.end() && *iter == a[pos] + nextJump && dfs(a, iter - a.begin(), nextJump, dp))
			{
				return true;
			}
		}
		
		nextJump = preJump;
		iter = lower_bound(a.begin() + pos, a.end(), a[pos] + nextJump);
		if (iter != a.end() && *iter == a[pos] + nextJump && dfs(a, iter - a.begin(), nextJump, dp))
		{
			return true;
		}
		
		nextJump = preJump + 1;
		iter = lower_bound(a.begin() + pos, a.end(), a[pos] + nextJump);
		if (iter != a.end() && *iter == a[pos] + nextJump && dfs(a, iter - a.begin(), nextJump, dp))
		{
			return true;
		}
		
		dp.insert(mp(pos, preJump));
		return false;
	}
};

/*
// use vector
class Solution {
public:
    bool canCross(vector<int>& stones) {
		int n = stones.size();
		if (n <= 1)
		{
			return true;
		}
		if (stones[1] != 1)
		{
			return false;
		}
		
        vector<vector<bool> > dp(n + 1);
		for (int i = 0; i < dp.size(); i++)
		{
			dp[i].insert(dp[i].end(), n + 1, false);
		}
		
		return dfs(stones, 1, 1, dp);
    }
	
	bool dfs(const vector<int> &a, int pos, int preJump, vector<vector<bool> > &dp)
	{
		if (dp[pos][preJump])
		{
			return false;
		}
			
		if (pos == a.size() - 1)
		{
			return true;
		}
		
		int nextJump;
		vector<int>::const_iterator iter;
		if (preJump > 1)
		{
			nextJump = preJump - 1;
			iter = lower_bound(a.begin() + pos, a.end(), a[pos] + nextJump);
			if (iter != a.end() && *iter == a[pos] + nextJump && dfs(a, iter - a.begin(), nextJump, dp))
			{
				return true;
			}
		}
		
		nextJump = preJump;
		iter = lower_bound(a.begin() + pos, a.end(), a[pos] + nextJump);
		if (iter != a.end() && *iter == a[pos] + nextJump && dfs(a, iter - a.begin(), nextJump, dp))
		{
			return true;
		}
		
		nextJump = preJump + 1;
		iter = lower_bound(a.begin() + pos, a.end(), a[pos] + nextJump);
		if (iter != a.end() && *iter == a[pos] + nextJump && dfs(a, iter - a.begin(), nextJump, dp))
		{
			return true;
		}
		
		dp[pos][preJump] = true;
		return false;
	}
};*/


int main()
{
	vector<int> a{0,1,3,5,6,8,12,17};
	Solution S;
	cout << S.canCross(a) << endl;
	return 0;
}