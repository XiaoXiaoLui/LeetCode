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
 
 int gcd(int a, int b)
 {
	 int c;
	 while (b)
	 {
		 c = b;
		 b = a % b;
		 a = c;
	 }
	 
	 return a;
 }
 
 ll calHash(const Point &p)
 {
	 ll a, b;

	 if (!p.x)
	 {
		 a = 0;
		 b = 1;
	 }
	 else if (!p.y)
	 {
		 a = 1;
		 b = 0;
	 }
	 else
	 {
		 int d = gcd(abs(p.x), abs(p.y));
		 a = p.x / d;
		 b = p.y / d;
	 }
	 

	 return a * (ll)1e9 + b;
 }
 
class Solution {
public:
    int maxPoints(vector<Point>& points) {
		if (points.size() <= 2)
		{
			return points.size();
		}
        int i, j, k, res, cnt, tmp, curBest;
		res = 2;
		
		unordered_map<ll, int> mm;
		
		for (i = 0; i < points.size(); i++)
		{
			mm.clear();
			cnt = 0;
			curBest = 0;
			for (j = 0; j < points.size(); j++)
			{
				Point tmp = points[j] - points[i];
				if (!tmp.x && !tmp.y)
				{
					cnt++;
				}
				else
				{
					curBest = max(curBest, ++mm[calHash(tmp)]);
				}
			}
			res = max(res, curBest + cnt);
		}
		return res;
    }	
};

int main()
{
	//[[0,0],[1,1],[1,-1]]
	vector<Point> points;;
	points.push_back(Point(0, 0));
	points.push_back(Point(1, 1));
	points.push_back(Point(1, -1));
	Solution S;
	cout << S.maxPoints(points);
	return 0;
}