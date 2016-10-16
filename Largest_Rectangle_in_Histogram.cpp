/******************************************************************************************
Largest Rectangle in Histogram
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

#define pii pair<int, int>
#define mp make_pair

typedef long long ll;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
		vector<int> left(heights.size());
		vector<int> right(heights.size());
		
		stack<int> S;
		
		int i;
		for (i = 0; i < heights.size(); i++)
		{
			while (!S.empty() && heights[i] <= heights[S.top()])
			{
				S.pop();
			}
			if (S.empty())
			{
				left[i] = i;
			}
			else
			{
				left[i] = i - S.top() - 1;
			}
			
			S.push(i);
		}
		
		// clear stack
		S = stack<int>();
		
		int res = 0;
		for (i = heights.size() - 1; i >= 0; i--)
		{
			while (!S.empty() && heights[i] <= heights[S.top()])
			{
				S.pop();
			}
			if (S.empty())
			{
				right[i] = heights.size() - 1 - i;
			}
			else
			{
				right[i] = S.top() - i - 1;
			}
			
			S.push(i);
			
			res = max(res, heights[i] * (left[i] + right[i] + 1));
		}
		
		return res;
    }
};

int main()
{
	int a[] = {2,1,5,6,2,3};
	vector<int> vec(a, a + sizeof(a) / sizeof(int));
	Solution S;
	cout << S.largestRectangleArea(vec);
	return 0;
}