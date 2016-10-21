/******************************************************************************************
Sliding Window Maximum
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
    vector<int> maxSlidingWindow(vector<int>& a, int k) {
		
        deque<int> Q;
		int i;
		vector<int> res;
		
		if (!a.size())
		{
			return res;
		}
		
		for (i = 0; i < k; i++)
		{
			while (!Q.empty() && a[i] >= a[Q.back()])
			{
				Q.pop_back();
			}
			Q.push_back(i);
		}
		res.push_back(a[Q.front()]);
		
		for (; i < a.size(); i++)
		{
			if (Q.front() <= i - k)
			{
				Q.pop_front();
			}
			while (!Q.empty() && a[i] >= a[Q.back()])
			{
				Q.pop_back();
			}
			Q.push_back(i);
			res.push_back(a[Q.front()]);
		}
		
		return res;
    }
};


int main()
{
	vector<int> a{1,3,-1,-3,5,3,6,7};
	Solution S;
	vector<int> ans = S.maxSlidingWindow(a, 3);
	for (auto e : ans)
	{
		cout << e << endl;
	}
	return 0;
}