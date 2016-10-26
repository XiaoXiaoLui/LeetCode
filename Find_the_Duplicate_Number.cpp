/******************************************************************************************
Find the Duplicate Number
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
    int findDuplicate(vector<int>& a) {
        
		int left, right, mid, n, i, cnt;
		n = a.size();
		right = n;
		left = 1;
		
		int ans = 0;
		if (countNum(a, left) > 1)
		{
			ans = 1;
		}
		else
		{
			while (right - left > 1)
			{
				mid = (right + left) / 2;
				if (countNum(a, mid) > mid)
				{
					right = mid;
				}
				else
				{
					left = mid;
				}
			}
			ans = right;
		}
		
		return ans;
    }
	
	int countNum(const vector<int> &a, int maxNum)
	{
		int res = 0;
		for (auto num : a)
		{
			if (num <= maxNum)
			{
				res++;
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