/******************************************************************************************
Find Minimum in Rotated Sorted Array II
******************************************************************************************/

#include<bits/stdc++.h>

using namespace std;

#define pii pair<int, int>
#define mp make_pair
#define INIT_UNORDER(mm) \
{\
	mm.max_load_factor(0.25);\
	mm.reserve(512);\
}\

typedef long long ll;


class Solution {
public:
    int findMin(vector<int>& a) {
        if (a.size() == 0)
		{
			return -1;
		}
		
		int res;
		if (a.front() > a.back())
		{
			res = *lower_bound(a.begin(), a.end(), a.back(), greater<int>());
		}
		else
		{
			vector<int>::iterator iter;
			for (iter = a.end() - 2; iter >= a.begin() && *iter == *(iter + 1); iter--);
			
			if (iter < a.begin())
			{
				res = a[0];
			}
			else
			{
				res = *lower_bound(a.begin(), iter, *iter, greater<int>());
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