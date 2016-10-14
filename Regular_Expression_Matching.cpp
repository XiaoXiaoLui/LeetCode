/**********************************************************************
Regular Expression Matching
**********************************************************************/

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

void genRandom(vector<int>& a, int n, int low, int high)
{
	srand(time(0));
	for (int i = 0; i < n; i++)
	{
		a.push_back(rand() % (high - low) + low);
	}
}

void print(vector<int> &a)
{
	for (int i = 0; i < a.size(); i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

// O(n^3logn)
class Solution {
public:
    bool isMatch(string s, string p) {
		count = 0;
		return match(s, p, 0, 0);
    }

	ll count;
	bool match(const string &s, const string &p, int i, int j)
	{
		int k, oldJ = j;
		map<pii, bool>::iterator iter;
		count++;
		if ((iter = dp.find(mp(i, j))) != dp.end())
		{
			return iter->second;
		}
		
		bool res = false;
		if (i < s.size() && j >= p.size())
		{
			res = false;
		}
		else if (i >= s.size() && j >= p.size())
		{
			res = true;
		}
		else if (i >= s.size() && j < p.size())
		{
			if ((p.size() - j) & 1)
			{
				res = false;
			}
			else
			{
				res = true;
				for (k = j + 1; k < p.size(); k += 2)
				{
					count++;
					if (p[k] != '*')
					{
						res = false;
						break;
					}
				}
			}
		}
		else
		{
			if (j < p.size() - 1 && p[j + 1] == '*')
			{
				j++;
			}
			
			if (s[i] == p[j] || p[j] == '.')
			{
				res = match(s, p, i + 1, j + 1);
			}
			else if (p[j] == '*')
			{
				res = false;
				for (k = i; k <= s.size(); k++)
				{
					count++;
					if (match(s, p, k, j + 1))
					{
						res = true;
						break;
					}
					
					if (s[k] != p[j - 1] && p[j - 1] != '.')
					{
						break;
					}
				}
			}
			else
			{
				res = false;
			}
			
			dp[mp(i, j)] = res;
		}
			
		dp[mp(i, oldJ)] = res;
		return res;
	}
	
	map<pii, bool> dp; 
};

int main()
{
	Solution S;
	string a, b;
	/*
	"aaaaaaaaaaaaab"
"a*a*a*a*a*a*a*a*a*a*c"
	*/
	a = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
	b = "a*a*a*a*a*a*a*a*a*a*aa*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*aa*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*aa*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*aa*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*aa*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*aa*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*aa*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*aa*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*c";
	bool ans = S.isMatch(a, b);
	printf("%d\n%lld\n%d\n", ans, S.count, S.dp.size());
	return 0;
}