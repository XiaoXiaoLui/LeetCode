/******************************************************************************************
 Trapping Rain Water
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
#include <stack>

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
    int trap(vector<int>& height) {
        int res = 0, i, left;
		pii tmp;
		stack<pii> S;
		for (i = 0; i < height.size(); i++)
		{
			left = i;
			while (!S.empty() && S.top().second <= height[i])
			{
				tmp = S.top();
				S.pop();
				if (!S.empty())
				{
					res += (min(height[i], S.top().second) - tmp.second) * (i - tmp.first);
				}
				left = tmp.first;
			}
			S.push(mp(left, height[i]));
		}
		
		return res;
    }
};

int main()
{
	Solution S;
	return 0;
}