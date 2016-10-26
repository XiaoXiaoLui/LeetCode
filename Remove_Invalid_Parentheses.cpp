/******************************************************************************************
Remove Invalid Parentheses
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
    vector<string> removeInvalidParentheses(string s) {
        ans.clear();
		ansSet.clear();
		
		stack<char> S;
		int bestCnt = 0;
		for (auto ch : s)
		{
			if (ch == '(')
			{
				S.push('(');
			}
			else if (ch == ')')
			{
				if (!S.empty())
				{
					bestCnt++;
					S.pop();
				}
			}
		}
		
		string curStr;
		solve(s, 0, curStr, 0, 0, bestCnt);
		return ans;
    }
	
	void solve(const string &s, int pos, string &curStr, int leftSum, int rightSum, int bestCnt)
	{
		if (pos == s.size())
		{
			if (leftSum == rightSum && leftSum == bestCnt && ansSet.count(curStr) == 0)
			{
				ans.push_back(curStr);
				ansSet.insert(curStr);
			}
			return;
		}
		
		int oldSize = curStr.size();
		if (s[pos] == '(')
		{
			solve(s, pos + 1, curStr, leftSum, rightSum, bestCnt);
			if (leftSum < bestCnt)
			{
				curStr += '(';
				solve(s, pos + 1, curStr, leftSum + 1, rightSum, bestCnt);
			}
		}
		else if (s[pos] == ')')
		{
			solve(s, pos + 1, curStr, leftSum, rightSum, bestCnt);
			if (rightSum < leftSum)
			{
				curStr += ')';
				solve(s, pos + 1, curStr, leftSum, rightSum + 1, bestCnt);
			}
		}
		else
		{
			curStr += s[pos];
			solve(s, pos + 1, curStr, leftSum, rightSum, bestCnt);
		}
		
		curStr.resize(oldSize);
	}
	
	vector<string> ans;
	set<string> ansSet;
};


int main()
{
	string a = "(a)())()";
	Solution S;
	vector<string> ans = S.removeInvalidParentheses(a);
	for (auto str : ans)
	{
		cout << str << endl;
	}
	return 0;
}