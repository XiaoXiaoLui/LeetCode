/******************************************************************************************
Count of Smaller Numbers After Self
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


// FenwickTree
struct FenwickTree
{
	FenwickTree(int num)
	{
		n = num;
		tr.resize(n + 2);
		fill(tr.begin(), tr.end(), 0);
	}
	
	int lowbit(int a)
	{
		return a & (-a);
	}
	
	void update(int i)
	{
		while (i <= n)
		{
			tr[i]++;
			i += lowbit(i);
		}
	}
	
	int query(int i)
	{
		int res = 0;
		while (i)
		{
			res += tr[i];
			i -= lowbit(i);
		}
		return res;
	}
	
	int n;
	vector<int> tr;
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& a) {
        
		int n = a.size();
		FenwickTree fwt(n);
		
		vector<int> b(a);
		sort(b.begin(), b.end());
		
		unordered_map<int, int> hash;
		int i, j;
		for (i = 0, j = 1; i < n; i++)
		{
			if (i > 0 && b[i] == b[i - 1])
			{
				continue;
			}
			hash[b[i]] = j++;
		}
		
		
		vector<int> ans(n);
		for (i = n - 1; i >= 0; i--)
		{
			fwt.update(hash[a[i]]);
			ans[i] = fwt.query(hash[a[i]] - 1);
		}
		
		return ans;
    }
};


int main()
{
	vector<int> a{5,2,6,1};
	Solution S;
	vector<int> ans = S.countSmaller(a);
	for (auto num : ans)
	{
		cout << num << endl;
	}
	return 0;
}