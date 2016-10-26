/******************************************************************************************
Expression Add Operators
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
    vector<string> addOperators(string s, int target) {
        ans.clear();
		if (s.size() == 0)
		{
			return ans;
		}
		
		string curStr;
		dfs(s, 0, curStr, 0, 0, target);
		
		return ans;
    }
	
	void dfs(const string &s, int pos, string curStr, ll sum, ll lastSum, ll target)
	{	
		if (pos == s.size() && target == sum)
		{
			ans.push_back(curStr);
			return;
		}
		
		int i;
		ll curNum = 0;
		string tmpStr;
		for (i = pos; i < s.size(); i++)
		{
			if (i != pos && curNum == 0)
			{
				break;
			}
			curNum = curNum * 10 + s[i] - '0';
			tmpStr += s[i];
			if (pos == 0)
			{
				dfs(s, i + 1, tmpStr, curNum, curNum, target);
			}
			else
			{
				dfs(s, i + 1, curStr + '+' + tmpStr, sum + curNum, curNum, target);
				dfs(s, i + 1, curStr + '-' + tmpStr, sum - curNum, -curNum, target);
				dfs(s, i + 1, curStr + '*' + tmpStr, sum - lastSum + lastSum * curNum, lastSum * curNum, target);
			}
		}
	}
	
	vector<string> ans;
};

void print(const vector<string> &vec)
{
	for (auto s : vec)
	{
		cout << s << " ";
	}
	cout << endl;
}

int main()
{
	vector<string> ans;
	Solution S;
	print(S.addOperators("123", 6));
	print(S.addOperators("232", 8));
	print(S.addOperators("105", 5));
	print(S.addOperators("00", 0));
	
	return 0;
}