/******************************************************************************************
Trapping Rain Water II
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

const int DIR[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

class Solution {
public:
    int trapRainWater(vector<vector<int> >& a) {
		if (!a.size())
		{
			return 0;
		}
		
        int i, j, k, curH, nextI, nextJ;
		n = a.size();
		m = a[0].size();
		
		vector<vector<int> > h(n);
		//vector<vector<bool> > visit(n);
		set<pair<int, pii> > S;
		for (i = 0; i < n; i++)
		{
			//visit[i].insert(visit[i].begin(), m, false);
			h[i].insert(h[i].begin(), m, MAX_HEIGHT);
		}
		
		for (j = 0; j < m; j++)
		{
			h[0][j] = a[0][j];
			h[n - 1][j] = a[n - 1][j];
			S.insert(mp(h[0][j], mp(0, j)));
			S.insert(mp(h[n - 1][j], mp(n - 1, j)));
		}
		for (i = 0; i < n; i++)
		{
			h[i][0] = a[i][0];
			h[i][m - 1] = a[i][m - 1];
			S.insert(mp(h[i][0], mp(i, 0)));
			S.insert(mp(h[i][m - 1], mp(i, m - 1)));
		}
		
		// loose k = m+n time
		
		while (!S.empty())
		{
			auto cur = *S.begin();
			S.erase(S.begin());
			
			curH = cur.first;
			i = cur.second.first;
			j = cur.second.second;
			for (k = 0; k < 4; k++)
			{
				nextI = i + DIR[k][0];
				nextJ = j + DIR[k][1];
				if (valid(nextI, nextJ) && curH < h[nextI][nextJ] && h[nextI][nextJ] != a[nextI][nextJ])
				{
					auto iter = S.find(mp(h[nextI][nextJ], mp(nextI, nextJ)));
					if (iter != S.end())
					{
						S.erase(iter);
					}
					h[nextI][nextJ] = max(curH, a[nextI][nextJ]);
					S.insert(mp(h[nextI][nextJ], mp(nextI, nextJ)));
				}
			}
		}
		
		
		ll ans = 0;
		for (i = 1; i < n - 1; i++)
		{
			for (j = 1; j < m - 1; j++)
			{
				ans += h[i][j] - a[i][j];
			}
		}
		
		return ans;
    }
	
	bool valid(int i, int j)
	{
		return i > 0 && i < n - 1 && j > 0 && j < m - 1;
	}
	
	int n, m;
	const int MAX_HEIGHT = 2e4 + 2;
};


int main()
{
	Solution S;
	vector<vector<int> > a{
  {1,4,3,1,3,2},
  {3,2,1,3,2,4},
  {2,3,3,2,3,1}};

	cout << S.trapRainWater(a) << endl;
	return 0;
}