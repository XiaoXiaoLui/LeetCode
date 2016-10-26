/******************************************************************************************
Patching Array
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
    int minPatches(vector<int>& nums, int n) {
        int i, res;
        long long miss;
		for (i = res = 0, miss = 1; miss <= n;)
		{
			if (i < nums.size() && nums[i] <= miss)
			{
				miss += nums[i++];
			}
			else
			{
				miss += miss;
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