/******************************************************************************************
Data Stream as Disjoint Intervals
******************************************************************************************/

#include<bits/stdc++.h>

using namespace std;

  struct Interval {
      int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
  };

#define pii pair<int, int>
#define mp make_pair
#define INIT_UNORDER(mm) \
{\
	mm.max_load_factor(0.25);\
	mm.reserve(512);\
}

typedef long long ll;

bool operator < (const Interval &a, const Interval &b)
{
	return a.end < b.end;
}

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class SummaryRanges {
public:
    /** Initialize your data structure here. */
    SummaryRanges() {
        S.clear();
		S.insert(Interval((int)-2e9, (int)-2e9));
		S.insert(Interval((int)2e9, (int)2e9));
    }
    
    void addNum(int val) {
        int left, right;
		
		auto iter = S.lower_bound(Interval(val, val));
		if (val <= iter->end && val >= iter->start)
		{
			return;
		}
		
		auto delIter = iter;
		if (val == iter->start - 1)
		{
			right = iter->end;
			left = iter->start - 1;
			iter--;
			S.erase(delIter);
		}
		else
		{
			iter--;
			left = right = val;
		}
		
		while (left == iter->end + 1)
		{
			delIter = iter;
			left = iter->start;
			iter--;
			S.erase(delIter);
		}
		
		S.insert(Interval(left, right));
    }
    
    vector<Interval> getIntervals() {
        set<Interval>::iterator iter, end;
		end = S.end();
		end--;
		
		vector<Interval> res;
		for (iter = S.begin(), iter++; iter != end; iter++)
		{
			res.push_back(*iter);
		}
		return res;
    }
	
	set<Interval> S;
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(val);
 * vector<Interval> param_2 = obj.getIntervals();
 */


int main()
{
	SummaryRanges S;
	vector<int> a{1, 3, 7, 2, 6};
	for (auto num : a)
	{
		S.addNum(num);
	}

	vector<Interval> ans = S.getIntervals();
	for (auto tmp : ans)
	{
		cout << tmp.start << " " << tmp.end << endl;
	}
	return 0;
}