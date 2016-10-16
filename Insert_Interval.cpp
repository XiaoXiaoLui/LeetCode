/******************************************************************************************
Insert Interval
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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> res;
		
		int i, left, right;
		for (i = 0; i < intervals.size() && intervals[i].start <= newInterval.start; i++)
		{
			res.push_back(intervals[i]);
		}
		
		left = newInterval.start;
		right = newInterval.end;
		if (i > 0)
		{
			if (newInterval.start <= intervals[i - 1].end)
			{
				left = intervals[i - 1].start;
				right = max(right, intervals[i - 1].end);
				res.pop_back();
			}
		}
		
		for (; i < intervals.size() && newInterval.end >= intervals[i].start ;i++)
		{
			right = max(right, intervals[i].end);
		}
		res.push_back(Interval(left, right));
		for (; i < intervals.size(); i++)
		{
			res.push_back(intervals[i]);
		}
		
		return res;
    }
};


int main()
{
	Solution S;
	return 0;
}