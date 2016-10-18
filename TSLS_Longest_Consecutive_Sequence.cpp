/******************************************************************************************
 Longest Consecutive Sequence
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

#define pii pair<int, int>
#define mp make_pair

typedef long long ll;

class Solution {
public:
    int longestConsecutive(vector<int>& a) {
		if (a.size() == 0)
		{
			return 0;
		}
        sort(a.begin(), a.end());
		
		int res, i, start;
		for (i = 1, start = 0, res = 1; i < a.size(); i++)
		{
			if (a[i] <= a[i - 1] + 1)
			{
				res = max(res, a[i] - a[start] + 1);
			}
			else
			{
				start = i;
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