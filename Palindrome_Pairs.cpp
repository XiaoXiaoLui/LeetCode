/******************************************************************************************
Palindrome Pairs
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
    vector<vector<int> > palindromePairs(vector<string>& words) {
        
		unordered_map<string, int> mm;
		set<int> S;
		int i;
		for (i = 0; i < words.size(); i++)
		{
			mm[words[i]] = i;
			S.insert(words[i].size());
		}
		
		vector<vector<int> > res;
		for (i = 0; i < words.size(); i++)
		{
			string str = words[i];
			reverse(str.begin(), str.end());
			
			if (mm.find(str) != mm.end() && mm[str] != i)
			{
				res.push_back({i, mm[str]});
			}
			
			auto itEnd = S.find(str.size());
			for (auto iter = S.begin(); iter != itEnd; iter++)
			{
				int pLen = *iter;
				if (isPal(str, 0, str.size() - pLen - 1) && mm.find(str.substr(str.size() - pLen, pLen)) != mm.end())
				{
					res.push_back({i, mm[str.substr(str.size() - pLen, pLen)]});
				}
				
				if (isPal(str, pLen, str.size() - 1) && mm.find(str.substr(0, pLen)) != mm.end())
				{
					res.push_back({mm[str.substr(0, pLen)], i});
				}
			}
		}
		return res;
    }
	
	bool isPal(const string &s, int left, int right)
	{
		while (left < right)
		{
			if (s[left] != s[right])
			{
				return false;
			}
			left++;
			right--;
		}
		return true;
	}
};


int main()
{
	vector<string> words{"abcd", "dcba", "lls", "s", "sssll"};
	Solution S;
	vector<vector<int> > ans = S.palindromePairs(words);
	for (auto tmp : ans)
	{
		cout << tmp[0] << " " << tmp[1] << endl;
	}
	return 0;
}