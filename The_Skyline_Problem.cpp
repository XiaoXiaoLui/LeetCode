/******************************************************************************************
The Skyline Problem
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
    vector<pair<int, int>> getSkyline(vector<vector<int>>& a) {
		
		int i, cur;
		vector<pii> lst;
		for (auto &e : a)
		{
			lst.push_back(mp(e[0], -e[2]));
			lst.push_back(mp(e[1], e[2]));
		}
		sort(lst.begin(), lst.end());
		
        multiset<int> S;
		S.insert(0);
		cur = 0;
		
		vector<pii> res;
		for (auto h : lst)
		{
			if (h.second < 0)
			{
				S.insert(-h.second);
			}
			else
			{
				S.erase(S.find(h.second));
			}
			
			if (*S.rbegin() != cur)
			{
				res.push_back(mp(h.first, *S.rbegin()));
				cur = *S.rbegin();
			}
		}
		
		return res;
    }
};

/*
class Solution {
public:
    vector<pair<int, int> > getSkyline(vector<vector<int> >& a) {

		set<pii> rhSet;
		set<pii> hrSet;
		vector<pair<int, int> > tmpVec;
		
		int i;
		ll left, right, height;
		pii tmp;
		hrSet.insert(mp(0LL, (ll)1e18));
		rhSet.insert(mp((ll)1e18, 0LL));
		height = 0;
		bool needInsert = false;
		for (i = 0; i < a.size(); i++)
		{
			left = a[i][0];
			right = a[i][1];
			
			while (!rhSet.empty() && rhSet.begin()->first < left)
			{
				tmp = *rhSet.begin();
				rhSet.erase(rhSet.begin());
				hrSet.erase(mp(tmp.second, tmp.first));
				
				if (hrSet.rbegin()->first < tmp.second)
				{
					tmpVec.push_back(mp((int)tmp.first, (int)hrSet.rbegin()->first));
				}
			}
			
			if (!needInsert && a[i][2] > hrSet.rbegin()->first)
			{
				needInsert = true;
			}
			
			height = max(height, (ll)a[i][2]);
			if (i + 1 == a.size() || a[i + 1][0] > left)
			{
				if (needInsert)
				{
					tmpVec.push_back(mp((int)left, (int)height));
				}
				height = 0;
				needInsert = false;
			}	
			rhSet.insert(mp(right, (ll)a[i][2]));
			hrSet.insert(mp((ll)a[i][2], right));
		}
		
		while (rhSet.size() > 1)
		{
			tmp = *rhSet.begin();
			rhSet.erase(rhSet.begin());
			hrSet.erase(mp(tmp.second, tmp.first));
			
			if (hrSet.rbegin()->first < tmp.second)
			{
				tmpVec.push_back(mp((int)tmp.first, (int)hrSet.rbegin()->first));
			}
		}
		
		return tmpVec;
    }
};*/


int main()
{
	//int a[][] = 
	vector<vector<int> > vec{{3,7,8},{3,8,7},{3,9,6},{3,10,5},{3,11,4},{3,12,3},{3,13,2},{3,14,1}};
	Solution S;
	vector<pair<int, int> > res = S.getSkyline(vec);
	for (auto tmp : res)
	{
		cout << tmp.first << " " << tmp.second << endl;
	}
	return 0;
}