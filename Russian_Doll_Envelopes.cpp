/******************************************************************************************
Russian Doll Envelopes
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

struct FenwickTree
{
	FenwickTree(int nn)
	{
		n = nn;
		tr.resize(n + 2);
		fill(tr.begin(), tr.end(), 0);
	}
	
	int lowbit(int a)
	{
		return a & (-a);
	}
	
	void update(int i, int val)
	{
		while (i <= n)
		{
			tr[i] = max(tr[i], val);
			i += lowbit(i);
		}
	}
	
	int query(int i)
	{
		int res = 0;
		while (i)
		{
			res = max(res, tr[i]);
			i -= lowbit(i);
		}
		return res;
	}
	
	int n;
	vector<int> tr;
};

bool cmp(const pii &a, const pii &b)
{
	if (a.first != b.first)
	{
		return a.first < b.first;
	}
	
	return a.second > b.second;
}

class Solution {
public:
    int maxEnvelopes(vector<pair<int, int> >& a) {
		int ans = 0;
		set<int> hSet;
		unordered_map<int, int> hHash;
		
        for (auto &p : a)
		{
			hSet.insert(p.second);
		}
		
		int m = 0;
		for (auto &h : hSet)
		{
			hHash[h] = ++m;
		}
		
		FenwickTree fwt(m);
		sort(a.begin(), a.end(), cmp);
		
		int cur;
		for (auto p : a)
		{
			cur = 1;
			cur = max(cur, fwt.query(hHash[p.second] - 1) + 1);
			fwt.update(hHash[p.second], cur);
			ans = max(cur, ans);
		}
		
		return ans;
    }
	

};

int main()
{
	vector<pii> a{{5,4},{6,4},{6,7},{2,3}};
	Solution S;
	cout << S.maxEnvelopes(a) << endl;
	return 0;
}