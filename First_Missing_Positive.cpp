/******************************************************************************************
First Missing Positive
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
    int firstMissingPositive(vector<int>& nums) {
		if (nums.size() == 0)
		{
			return 1;
		}
		
        int l, r;
		l = 0, r = nums.size();
		while (l < r)
		{
			if (nums[l] == l + 1)
			{
				l++;
			}
			else if (nums[l] < l + 1 || nums[l] > r || nums[nums[l] - 1] == nums[l])
			{
				nums[l] = nums[--r];
			}
			else
			{
				swap(nums[l], nums[nums[l] - 1]);
			}
		}
		
		return l + 1;
    }
};

int main()
{
	Solution S;
	return 0;
}