/******************************************************************************************
Search in Rotated Sorted Array
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

class Solution {
public:
    int search(vector<int>& nums, int target) {
		if (nums.size() == 0)
		{
			return -1;
		}
		
		int res = -1, pos;
		vector<int>::iterator iter, mid;
        mid = lower_bound(nums.begin(), nums.end() - 1, *nums.rbegin(), greater<int>());
		iter = lower_bound(nums.begin(), mid, target);
		if (*iter == target)
		{
			res = iter - nums.begin();
		}
		else
		{
			iter = lower_bound(mid, nums.end(), target);
			if (*iter == target)
			{
				res = iter - nums.begin();
			}
		}
		
		
		return res;
    }
};

int main()
{
	Solution S;
	vector<int> nums;
	nums.push_back(3);
	nums.push_back(1);
	S.search(nums, 1);
	return 0;
}