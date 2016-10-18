/******************************************************************************************
Max Points on a Line
******************************************************************************************/

#include<bits/stdc++.h>

using namespace std;

#define pii pair<int, int>
#define mp make_pair



  struct Point {
      int x;
      int y;
      Point() : x(0), y(0) {}
      Point(int a, int b) : x(a), y(b) {}
  };

/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
 typedef long long ll;
 Point operator + (const Point &p1, const Point &p2)
 {
	 return Point(p1.x + p2.x, p1.y + p2.y);
 }
 
 Point operator - (const Point &p1, const Point &p2)
 {
	 return Point(p1.x - p2.x, p1.y - p2.y);
 }
 
 // Cross product, 0 means 2 vector on the same line
 int operator * (const Point &p1, const Point &p2)
 {
	 return p1.x*p2.y - p1.y*p2.x;
 }
 
 bool operator == (const Point &p1, const Point &p2)
 {
	 return p1.x == p2.x && p1.y == p2.y;
 }
 
class Solution {
public:
    int maxPoints(vector<Point>& points) {
		if (points.size() <= 2)
		{
			return points.size();
		}
        int i, j, k, res, cnt;
		res = 2;
		
		unordered_map<ll, int> mm;
		for (i = 0; i < points.size(); i++)
		{
			res = max(res, ++mm[calHash(points[i])]);
		}
		
		for (i = 0; i < points.size(); i++)
		{
			for (j = i + 1; j < points.size(); j++)
			{
				if (points[i] == points[j])
				{
					continue;
				}
				cnt = 2;
				Point curVec = points[j] - points[i];
				for (k = 0; k < points.size(); k++)
				{
					if (k == i || k == j)
					{
						continue;
					}
					if ((points[k] - points[i]) * curVec == 0)
					{
						cnt++;
					}
				}
				res = max(res, cnt);
			}
		}
		return res;
    }
	
	ll calHash(const Point &p)
	{
		return (ll)p.x * (int)1e9 + p.y;
	}
	
};

int main()
{
	Solution S;
	return 0;
}