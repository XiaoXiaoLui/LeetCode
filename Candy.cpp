/******************************************************************************************
Candy
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
    int candy(vector<int>& a) {
		if (a.size() == 0)
		{
			return 0;
		}
		if (a.size() == 1)
		{
			return 1;
		}
		
        vector<int> ans(a.size() + 2);
		int i, j, next, n;
		n = a.size();
		
		int cnt = 0;
		
		if (a[0] < a[1])
		{
			ans[0] = 1;
		}
		for (i = 0; i < n; i = next)
		{	
			if (i == n - 1)
			{
				if (a[i] <= a[i - 1])
				{
					ans[i] = 1;
				}
				else
				{
					ans[i] = ans[i - 1] + 1;
				}
					
				break;
			}
			else if (a[i] > a[i + 1])
			{
				for (j = i + 1; j < n - 1 && a[j] > a[j + 1]; j++);
				next = j + 1;
				ans[j] = 1;
				for (j--; j > i; j--)
				{
					ans[j] = ans[j + 1] + 1;
				}
				if (i == 0 || a[i] <= a[i - 1])
				{
					ans[i] = ans[i + 1] + 1;
				}
				else
				{
					ans[i] = max(ans[i - 1] + 1, ans[i + 1] + 1);
				}
			}
			else
			{
				if (i == 0 || a[i] <= a[i - 1])
				{
					ans[i] = 1;
				}
				else
				{
					ans[i] = ans[i - 1] + 1;
				}
				next = i + 1;
			}
		}
		
		for (i = 0; i < n; i++)
		{
			cnt += ans[i];
		}
		return cnt;
    }
};

int main()
{
	int a[] = {2, 2};
	Solution S;
	vector<int> vec(a, a + 2);
	S.candy(vec);
	return 0;
}