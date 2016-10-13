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


#define pii pair<int, int>
#define mp make_pair<int, int>

typedef long long ll;

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

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i, j, k, idx;
		double res = 0;
		
		idx = ((nums1.size() + nums2.size()) + 1) / 2;
		k = 0;
		for (i = 0, j = 0, k = 0; k < idx && i < nums1.size() && j < nums2.size(); k++)
		{
			if (nums1[i] <= nums2[j])
			{
				res = nums1[i];
				i++;
			}
			else
			{
				res = nums2[j];
				j++;
			}
		}
		while (k < idx && i < nums1.size())
		{
			res = nums1[i];
			k++;
			i++;
		}
		while (k < idx && j < nums2.size())
		{
			res = nums2[j];
			k++;
			j++;
		}
		
		if ((nums1.size() + nums2.size()) % 2 == 0)
		{
			if (i == nums1.size())
			{
				res += nums2[j];
			}
			else if (j == nums2.size())
			{
				res += nums1[i];
			}
			else if (nums1[i] <= nums2[j])
			{
				res += nums1[i];
			}
			else
			{
				res += nums2[j];
			}
			res /= 2;
		}
		
		return res;
    }
};


int main()
{
	vector<int> a, b;
	int n, low, high;
	low = 0;
	high = 10;
	genRandom(a, 4, low, high);
	genRandom(b, 5, low, high);
	
	
	Solution s;
	int ans = s.findMedianSortedArrays(a, b);
	
	print(a);
	print(b);
	printf("%d\n", ans);
	return 0;
}