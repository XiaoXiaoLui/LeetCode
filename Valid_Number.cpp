/******************************************************************************************
Valid Number
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

class Solution {
public:
    bool isNumber(string s) {
        string tmp;
		int i, j;
		for (i = 0; i < s.size() && s[i] == ' '; i++);
		s.erase(0, i);
		for (i = s.size() - 1; i >= 0 && s[i] == ' '; i--);
		s.erase(i + 1);
		
		if (s.size() == 0)
		{
			return false;
		}
		
		bool ok = true;
		int c1, c2;
		c1 = c2 = 0;
		
		if (!isdigit(s[0]) && s[0] != '+' && s[0] != '-' && s[0] != '.')
		{
			return false;
		}
		if (s[0] == '.')
		{
			if (s.size() == 1)
			{
				return false;
			}
			c1++;
		}
		
		bool hasDigit = false;
		if (isdigit(s[0]))
		{
			hasDigit = true;
		}
		
		for (i = 1; i < s.size(); i++)
		{
			if (!isdigit(s[i]) && s[i] != '.' && s[i] != 'e' && s[i] != '+' && s[i] != '-')
			{
				return false;
			}
			else if (s[i] == '+' || s[i] == '-')
			{
				if (s[i - 1] != 'e' || i == s.size() - 1 || !isdigit(s[i + 1]))
				{
					return false;
				}
			}
			else if (s[i] == '.')
			{
				if (c2)
				{
					return false;
				}
				c1++;
				if (c1 > 1)
				{
					return false;
				}
			}
			else if (s[i] == 'e')
			{
				if (i == s.size() - 1 || !hasDigit)
				{
					return false;
				}
				c2++;
				if (c2 > 1)
				{
					return false;
				}
			}
			else
			{
				hasDigit = true;
			}
		}
		
		if (!hasDigit && (c1 || c2))
		{
			return false;
		}
		
		return ok;
    }
};

int main()
{
	Solution S;
	
	printf("%d %d %d %d %d", S.isNumber("0"), S.isNumber(" 0.1 "), S.isNumber("abc"), S.isNumber("1 a"), S.isNumber("2e10"));
	return 0;
}