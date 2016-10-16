/******************************************************************************************
Minimum Window Substring
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
    string minWindow(string s, string t) {
        int i, j, tot = 0, cur;
		
		memset(cnt1, 0, sizeof(cnt1));
		memset(cnt2, 0, sizeof(cnt2));
		
		for (i = 0; i < t.size(); i++)
		{
			cnt2[t[i]]++;
		}
		tot = t.size();
		
		
		int ansI, ansJ;
		int ansLen = (int)1e9;
		for (i = 0, j = 0, cur = 0; i < s.size();)
		{
			if (cur < tot)
			{
				if (j == s.size())
				{
					break;
				}
				
				cnt1[s[j]]++;
				if (cnt1[s[j]] <= cnt2[s[j]])
				{
					cur++;
				}

				j++;
			}
			else
			{
				cnt1[s[i]]--;
				if (cnt1[s[i]] < cnt2[s[i]])
				{
					cur--;
				}

				i++;
			}
			
			if (cur == tot && j - i < ansLen)
			{
				ansI = i;
				ansJ = j;
				ansLen = j - i;
			}
		}
		
		if (ansLen == (int)1e9)
		{
			return "";
		}
		else
		{
			return s.substr(ansI, ansLen);
		}
    }
	
	int cnt1[130];
	int cnt2[130];
};

int main()
{
	string a = "ab";
	string b = "b";
	Solution S;
	
	cout << S.minWindow(a, b) << endl;
	return 0;
}