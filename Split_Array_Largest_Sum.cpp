/******************************************************************************************
Split Array Largest Sum
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
    int splitArray(vector<int>& a, int m) {
        int n = a.size();
		
		ll left, right, mid;
		left = right = 0LL;
		for (auto num : a)
		{
			right += num;
		}
		
		while (right - left > 1)
		{
			mid = (left + right) / 2;
			int cnt = 1;
			ll curSum = 0LL;
			bool ok = true;
			for (auto num : a)
			{
				if (curSum + num > mid)
				{
					cnt++;
					curSum = 0LL;
				}
				
				curSum += num;
				if (curSum > mid || cnt > m)
				{
					ok = false;
					break;
				}
			}
			
			if (ok)
			{
				right = mid;
			}
			else
			{
				left = mid;
			}	
		}
		
		return right;
    }
};

int main()
{
	vector<int> nums = {7,2,5,10,8};
	int m = 2;
	Solution S;
	cout << S.splitArray(nums, m) << endl;
	return 0;
}