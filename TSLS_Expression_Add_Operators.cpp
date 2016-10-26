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

const string OP[4] = {"", "+", "-", "*"};

class Solution {
public:
    vector<string> addOperators(string s, int target) {
        ans.clear();
		if (s.size() == 0)
		{
			return ans;
		}
		
		string cur;
		dfs(cur, s, 0, target);
		
		return ans;
    }
	
	void dfs(string &cur, const string &s, int i, int target)
	{
		cur.push_back(s[i]);
		
		int oldSize = cur.size();
		if (i + 1 == s.size())
		{
			if (calculate(cur) == target)
			{
				ans.push_back(cur);
			}
			return;
		}
		
		int preSize;
		for (int k = 0; k < 4; k++)
		{
			preSize = cur.size();
			cur += OP[k];
			dfs(cur, s, i + 1, target);
			cur.resize(preSize);
		}
		
		cur.resize(oldSize);
	}
	
	int calculate(const string &s) {
		int i, n, res;
		n = s.size();
		res = 0;
		
		stack<int> numS;
		stack<char> opS;
		for (i = 0; i < s.size(); i++)
		{			
			if (isdigit(s[i]))
			{
				int a = s[i] - '0';
				for (i++; i < s.size(); i++)
				{
					if (isdigit(s[i]))
					{
						if (a == 0)
						{
							return INVALID;
						}
						a = a * 10 + s[i] - '0';
					}
					else
					{
						i--;
						break;
					}
				}
				numS.push(a);
			}
			else
			{
				if (opS.empty() || !prior(opS.top(), s[i]))
				{
					opS.push(s[i]);
				}
				else
				{
					int p1, p2;
					p2 = numS.top();
					numS.pop();
					p1 = numS.top();
					numS.pop();
					
					numS.push(cal(opS.top(), p1, p2));
					opS.pop();
					i--;
				}
			}
		}
		
		while (!opS.empty())
		{
			int p1, p2;
			p2 = numS.top();
			numS.pop();
			p1 = numS.top();
			numS.pop();
			
			numS.push(cal(opS.top(), p1, p2));
			opS.pop();
		}
		
		return numS.top();
	}
	
private:
	bool prior(char op1, char op2)
	{
		return priNum(op1) >= priNum(op2);
	}
	int priNum(char op)
	{
		int res = 0;
		switch (op)
		{
		case '+':
		case '-':
			res = 1;
			break;
		case '*':
		case '/':
			res = 2;
			break;
		default:
			break;
		}
		return res;
	}
	
	int cal(char ch, int p1, int p2)
	{
		int res = 0;
		switch (ch)
		{
		case '+':
			res = p1 + p2;
			break;
		case '-':
			res = p1 - p2;
			break;
		case '*':
			res = p1 * p2;
			break;
		case '/':
			res = p1 / p2;
			break;
		default:
			break;
		}
		return res;
	}
	
	vector<string> ans;
	const static int INVALID = -2e9;
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