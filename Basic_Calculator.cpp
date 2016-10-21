/******************************************************************************************
Basic Calculator
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
    int calculate(string s) {
        int i, n, res;
		n = s.size();
		res = 0;
		
		stack<int> numS;
		stack<char> opS;
		for (i = 0; i < s.size(); i++)
		{
			if (s[i] == ' ')
			{
				continue;
			}
			
			if (isdigit(s[i]))
			{
				int a = s[i] - '0';
				for (i++; i < s.size(); i++)
				{
					if (s[i] == ' ')
					{
						continue;
					}
					if (isdigit(s[i]))
					{
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
				if (s[i] == '(')
				{
					opS.push('(');
				}
				else if (s[i] == ')' && opS.top() == '(')
				{
					opS.pop();
				}
				else if (opS.empty() || !prior(opS.top(), s[i]))
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
		case '(':
		case ')':
			res = 0;
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
};


int main()
{
	string expr = "(1+(4+5+2)-3)+(6+8)";
	Solution S;
	cout << S.calculate(expr) << endl;
	return 0;
}