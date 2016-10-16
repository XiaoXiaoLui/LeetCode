/******************************************************************************************
Merge Intervals
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

using namespace std;

#define pii pair<int, int>
#define mp make_pair

typedef long long ll;

struct Interval {
     int start;
     int end;
     Interval() : start(0), end(0) {}
     Interval(int s, int e) : start(s), end(e) {}
};
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
	static bool cmp(const Interval &a, const Interval &b)
	{
		return a.start < b.start;
	}

    vector<Interval> merge(vector<Interval>& intervals) {
		resVec.clear();
		if (intervals.size() == 0)
		{
			return resVec;
		}
		
		sort(intervals.begin(), intervals.end(), cmp);
		
		int i;
		Interval cur = intervals[0];
		for (i = 1; i < intervals.size(); i++)
		{
			if (!merge2Int(cur, intervals[i]))
			{
				resVec.push_back(cur);
				cur = intervals[i];
			}
		}
		resVec.push_back(cur);
		
		return resVec;
    }
	
	bool merge2Int(Interval &a, const Interval &b) const
	{
		Interval c;
		if (b.start > a.end)
		{
			return false;
		}
		
		a.end = max(a.end, b.end);
		return true;
	}
	
	vector<Interval> resVec;
};

int main()
{
	Solution S;
	return 0;
}