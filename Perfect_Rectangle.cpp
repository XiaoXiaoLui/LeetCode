/******************************************************************************************
Perfect Rectangle
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
	struct MyHash
	{
		size_t operator()(const pii &p) const
		{
			ll tmp = ((ll)p.first) << 32 + p.second;
			return obj(tmp);
		}
		hash<ll> obj;
	};
	
	int countBit(int a)
	{
		int res = 0;
		while (a)
		{
			res += a & 1;
			a >>= 1;
		}
		
		return res;
	}
	
    bool isRectangleCover(vector<vector<int> >& rect) {
        
		int left, right, up, down;
		ll area = 0LL;
		left = INT_MAX;
		right = INT_MIN;
		up = INT_MIN;
		down = INT_MAX;
		
		pii p0, p1, p2, p3;
		
		//unordered_map<pii, int, MyHash> mm; // unordered_map gets TLE
		map<pii, int> mm;
		
		for (auto &a : rect)
		{
			left = min(left, a[0]);
			right = max(right, a[2]);
			down = min(down, a[1]);
			up = max(up, a[3]);
			
			p0 = mp(a[0], a[1]);
			p1 = mp(a[2], a[1]);
			p2 = mp(a[2], a[3]);
			p3 = mp(a[0], a[3]);
			
			if (mm[p0] & 1)
			{
				return false;
			}
			if (mm[p1] & 2)
			{
				return false;
			}
			if (mm[p2] & 4)
			{
				return false;
			}
			if (mm[p3] & 8)
			{
				return false;
			}
			
			mm[p0] |= 1;
			mm[p1] |= 2;
			mm[p2] |= 4;
			mm[p3] |= 8;
			
			area += (ll)(a[3] - a[1]) * (a[2] - a[0]);
		}
		
		int oddNum = 0;
		for (auto &p : mm)
		{
			int cnt = countBit(p.second);
			if (cnt == 3)
			{
				return false;
			}
			if (cnt == 1)
			{
				oddNum++;
				if (oddNum > 4)
				{
					return false;
				}
			}
		}
		
		if (oddNum != 4)
		{
			return false;
		}
		
		if (area != (ll)(right - left)*(up - down))
		{
			return false;
		}
		
		return true;
    }
};



/*
0 0 1 1 1 0 0 0 0 0
0 0 1 1 1 0 0 0 0 0
0 1 1 1 1 1 1 1 0 0
1 2 2 2 2 2 2 2 1 1
1 1 1 1 1 1 1 1 1 1

*/

int main()
{
	vector<vector<int> > rect4 = {
  {1,1,3,3},
  {3,1,4,2},
  {1,3,2,4},
  {2,2,4,4}
};
	vector<vector<int> > rect1 =   {{1,1,3,3},
  {3,1,4,2},
  {3,2,4,4},
  {1,3,2,4},
  {2,3,3,4}
};
	
	vector<vector<int> > rect2 = {
  {1,1,2,3},
  {1,3,2,4},
  {3,1,4,2},
  {3,2,4,4}
};
	vector<vector<int> > rect3 = {
  {1,1,3,3},
  {3,1,4,2},
  {1,3,2,4},
  {3,2,4,4}
};
	
	Solution S;
	cout << S.isRectangleCover(rect1) << endl;
	cout << S.isRectangleCover(rect2) << endl;
	cout << S.isRectangleCover(rect3) << endl;
	cout << S.isRectangleCover(rect4) << endl;
	//cout << S.isRectangleCover(rect5) << endl;
	
	
	/*
	SegmentTree2D st(10, 5);
	st.update(mp(3,4), mp(5, 5));
	st.update(mp(2, 2), mp(8, 3));
	st.update(mp(1, 1), mp(10, 2));
	
	cout << st.query(mp(3, 3), mp(5, 5)) << endl;
	cout << st.query(mp(1, 1), mp(7, 4)) << endl;*/
	return 0;
}


/*
*/