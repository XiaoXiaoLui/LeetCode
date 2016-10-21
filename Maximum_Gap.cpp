/******************************************************************************************
Maximum Gap
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
    int maximumGap(vector<int>& a) {
		if (a.size() < 2)
		{
			return 0;
		}
		
        int n, i, idx;
		n = a.size();
		vector<pii> bucket(n, mp(1e9, -1e9));
		int minV, maxV;
		for (i = 0, minV = 1e9, maxV = -1e9; i < n; i++)
		{
			minV = min(minV, a[i]);
			maxV = max(maxV, a[i]);
		}
		
		int q = (maxV - minV) / (n - 1);
		int r = (maxV - minV) % (n - 1);
		int offset = minV + (q + 1) * r;
		
		bucket[0] = mp(minV, minV);
		bucket[n - 1] = mp(maxV, maxV);
		for (i = 0; i < n; i++)
		{
			if (a[i] == maxV)
			{
				continue;
			}
			if (a[i] >= offset)
			{
				idx = r;
				if (q)
				{
					idx += (a[i] - offset) / q;
				}
			}
			else
			{
				idx = (a[i] - minV) / (q + 1);
			}
			bucket[idx].first = min(bucket[idx].first, a[i]);
			bucket[idx].second = max(bucket[idx].second, a[i]);
		}
		
		int res = 0, right;
		for (i = 1, right = bucket[0].second; i < n; i++)
		{
			if (bucket[i].first <= bucket[i].second)
			{
				res = max(res, bucket[i].first - right);
				right = bucket[i].second;
			}
		}
		
		return res;
    }
};

int main()
{
	vector<int> a{15252,16764,27963,7817,26155,20757,3478,22602,20404,6739,16790,10588,16521,6644,20880,15632,27078,25463,20124,15728,30042,16604,17223,4388,23646,32683,23688,12439,30630,3895,7926,22101,32406,21540,31799,3768,26679,21799,23740};
	sort(a.begin(), a.end());
	int maxGap = -1, left, right, pre = 1e9 + 5;
	
	for (auto e : a)
	{
		cout << e << " ";
		if (e - pre > maxGap)
		{
			maxGap = e - pre;
			left = pre;
			right = e;
		}
		pre = e;
	}
	cout << endl;
	cout << maxGap << "  " << left << " " << right << endl;
	Solution S;
	cout << S.maximumGap(a) << endl;
	return 0;
}