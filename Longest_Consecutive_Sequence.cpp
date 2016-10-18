/******************************************************************************************
 Longest Consecutive Sequence
******************************************************************************************/
#include<bits/stdc++.h>

using namespace std;

#define pii pair<int, int>
#define mp make_pair

typedef long long ll;

class Solution {
public:
    int longestConsecutive(vector<int>& a) {
		if (a.size() == 0)
		{
			return 0;
		}
        
		unordered_set<int> totalSet;
		unordered_set<int> visitSet;
		totalSet.max_load_factor(0.25);
		totalSet.reserve(512);
		visitSet.max_load_factor(0.25);
		visitSet.reserve(512);
		
		
		int i, res;
		for (i = 0; i < a.size(); i++)
		{
			totalSet.insert(a[i]);
		}
		
		int cnt, left, right;
		res = 0;
		for (i = 0; i < a.size(); i++)
		{
			if (visitSet.find(a[i]) != visitSet.end())
			{
				continue;
			}
			cnt = 1;
			visitSet.insert(a[i]);
			for (left = a[i] - 1; totalSet.find(left) != totalSet.end(); left--)
			{
				visitSet.insert(left);
				cnt++;
			}
			for (right = a[i] + 1; totalSet.find(right) != totalSet.end(); right++)
			{
				visitSet.insert(right);
				cnt++;
			}
			
			res = max(res, cnt);
		}
		return res;
    }
};

int main()
{
	Solution S;
	
	
	
	return 0;
}