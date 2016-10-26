/******************************************************************************************
Remove Duplicate Letters
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
    string removeDuplicateLetters(string s) {
        
		if (!s.size())
		{
			return "";
		}
		
		int cnt[26];
		memset(cnt, 0, sizeof(cnt));
		int i, pos;
		for (auto ch : s)
		{
			cnt[ch - 'a']++;
		}
		for (i = 0, pos = 0; i < s.size(); i++)
		{
			if (s[i] < s[pos])
			{
				pos = i;
			}
			if (--cnt[s[i] - 'a'] == 0)
			{
				break;
			}
		}
		
		string next;
		for (i = pos + 1; i < s.size(); i++)
		{
			if (s[i] != s[pos])
			{
				next.push_back(s[i]);
			}
		}
		
		return s[pos] + removeDuplicateLetters(next);
    }
};


int main()
{
	Solution S;
	cout << S.removeDuplicateLetters("bcabc") << endl;
	cout << S.removeDuplicateLetters("cbacdcbc") << endl;
	return 0;
}