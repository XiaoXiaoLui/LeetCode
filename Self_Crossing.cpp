/******************************************************************************************
Self Crossing
******************************************************************************************/

#include<bits/stdc++.h>

using namespace std;

#define pii pair<int, int>
#define pp pair<pii, pii>
#define pll pair<ll, ll>
#define mp make_pair
#define INIT_UNORDER(mm) \
{\
	mm.max_load_factor(0.25);\
	mm.reserve(512);\
}

typedef long long ll;

//const int DIR[4][2] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};

class Solution {
public:
    bool isSelfCrossing(vector<int>& a) {
		int n = a.size();
        if (n < 4)
		{
			return false;
		}
		
		int left, right, up, down, i, r;
		int x, y;
		x = y = 0;
		right = 0;
		y += a[0];
		up = y;
		x -= a[1];
		left = x;
		y -= a[2];
		down = y;
		x += a[3];
		
		if (x >= 0 && y >= 0)
		{
			return true;
		}
		else if (x > 0 && y < 0)
		{
			int preLeft, preRight, preDown, preUp;
			preLeft = 2e9;
			preRight = -2e9;
			preUp = -2e9;
			preDown = 0;
			
			bool loop = true;
			for (i = 4; loop && i < a.size(); i++)
			{
				switch (i % 4)
				{
				case 0:
				y += a[i];
				if (y > up)
				{
					preRight = right;
					right = x;
				}
				else if (y >= preDown)
				{
					up = y;
					left = right;
					right = x;
					loop = false;
				}
				else
				{
					up = y;
					right = x;
					loop = false;
				}
				break;
				case 1:
				x -= a[i];
				if (x < left)
				{
					preUp = up;
					up = y;
				}
				else if (x <= preRight)
				{
					left = x;
					down = up;
					up = y;
					loop = false;
				}
				else
				{
					left = x;
					up = y;
					loop = false;
				}
				break;
				case 2:
				y -= a[i];
				if (y < down)
				{
					preLeft = left;
					left = x;
				}
				else if (y <= preUp)
				{
					right = left;
					left = x;
					down = y;
					loop = false;
				}
				else
				{
					left = x;
					down = y;
					loop = false;
				}
				break;
				case 3:
				x += a[i];
				if (x > right)
				{
					preDown = down;
					down = y;
				}
				else if (x >= preLeft)
				{
					up = down;
					down = y;
					right = x;
					loop = false;
				}
				else
				{
					right = y;
					down = x;
					loop = false;
				}
				break;
				}
			}
			
			for (; i < a.size(); i++)
			{
				switch (i % 4)
				{
				case 0:
				y += a[i];
				if (y >= up)
				{
					return true;
				}
				up = y;
				break;
				case 1:
				x -= a[i];
				if (x <= left)
				{
					return true;
				}
				left = x;
				break;
				case 2:
				y -= a[i];
				if (y <= down)
				{
					return true;
				}
				down = y;
				break;
				case 3:
				x += a[i];
				if (x >= right)
				{
					return true;
				}
				right = x;
				break;
				}
				
			}
			
			return false;
		}
		else
		{
			if (x == 0)
			{
				up = 0;
			}
			right = x;
			
			for (i = 4; i < a.size(); i++)
			{
				switch (i % 4)
				{
				case 0:
				y += a[i];
				if (y >= up)
				{
					return true;
				}
				up = y;
				break;
				case 1:
				x -= a[i];
				if (x <= left)
				{
					return true;
				}
				left = x;
				break;
				case 2:
				y -= a[i];
				if (y <= down)
				{
					return true;
				}
				down = y;
				break;
				case 3:
				x += a[i];
				if (x >= right)
				{
					return true;
				}
				right = x;
				break;
				}
				
			}
			
			return false;
		}
	
    }
};


int main()
{
	Solution S;
	return 0;
}