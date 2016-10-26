/******************************************************************************************
Create Maximum Number
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

class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int len1, len2, i, j;
		
		len1 = nums1.size();
		len2 = nums2.size();
		
		vector<int> res;
		
		for (i = max(0, k - len2); i <= k && i <= len1; i++)
		{
			j = k - i;
			
			auto const &res1 = maxVec(nums1, i);
			auto const &res2 = maxVec(nums2, j);
		
			res = max(res, merge(res1, res2));
		}
		
		return res;
    }
	
	vector<int> maxVec(const vector<int> &a, int k)
	{
		vector<int> res;
		for (int i = 0; i < a.size(); i++)
		{
			while (!res.empty() && a.size() - i + res.size() > k && a[i] > res.back())
			{
				res.pop_back();
			}
			res.push_back(a[i]);
		}
		while (res.size() > k)
		{
			res.pop_back();
		}
		return res;
	}
	
	bool notLess(const vector<int> &a, const vector<int> &b, int i, int j)
	{
		for (; i < a.size() && j < b.size(); i++, j++)
		{
			if (a[i] != b[j])
			{
				return a[i] >= b[j];
			}
		}
		
		return j == b.size();
	}
	
	vector<int> merge(const vector<int> &a, const vector<int> &b)
	{
		vector<int> res;
		int i, j;
		for (i = j = 0; i < a.size() && j < b.size(); )
		{
			if (notLess(a, b, i, j))
			{
				res.push_back(a[i++]);
			}
			else
			{
				res.push_back(b[j++]);
			}
		}
		
		for (; i < a.size(); i++)
		{
			res.push_back(a[i]);
		}
		for (; j < b.size(); j++)
		{
			res.push_back(b[j]);
		}
		
		return res;
	}
};


int main()
{
	vector<int> a{6, 7};
	vector<int> b{6, 0, 4};
	Solution S;
	
	vector<int> ans = S.maxNumber(a, b, 5);
	for (auto num : ans)
	{
		cout << num << endl;
	}
	return 0;
}