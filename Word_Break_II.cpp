/******************************************************************************************
Word Break II
******************************************************************************************/

#include<bits/stdc++.h>

using namespace std;

#define pii pair<int, int>
#define mp make_pair

typedef long long ll;

class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
		vector<int> dp(s.size() + 1, 0);
		next.clear();
		next.resize(s.size() + 1);
		ans.clear();
		
		int i, j;
		dp[s.size()] = 1;
		for (i = s.size() - 1; i >= 0; i--)
		{
			for (j = i; j < s.size(); j++)
			{
				if (dp[j + 1] && wordDict.find(s.substr(i, j - i + 1)) != wordDict.end())
				{
					dp[i] = 1;
					next[i].push_back(j + 1);
				}
			}
		}
		
		if (!s.size()  || !dp[0])
		{
			return ans;
		}
		
		string cur;
		dfs(s, 0, cur);
		
		return ans;
    }
	
	void dfs(const string &s, int i, string &cur)
	{
		int oldLen = cur.size();
		for (auto j : next[i])
		{
			if (j == s.size())
			{
				cur += s.substr(i, j - i);
				ans.push_back(cur);
			}
			else
			{
				cur += s.substr(i, j - i);
				cur.push_back(' ');
				dfs(s, j, cur);
			}
			cur.resize(oldLen);
		}
	}
	
	vector<string> ans;
	vector<vector<int> > next;
};

int main()
{
	Solution S;
	return 0;
}