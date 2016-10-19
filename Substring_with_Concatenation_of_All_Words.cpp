/******************************************************************************************
Substring with Concatenation of All Words
******************************************************************************************/


#include<bits/stdc++.h>

using namespace std;

#define pii pair<int, int>
#define mp make_pair
#define setMap(mm) \
{\
	mm.max_load_factor(0.25);\
	mm.reserve(512);\
}\

typedef long long ll;


// moving windows 
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
		unordered_map<string, int> initMap, curMap;
		setMap(initMap);
		setMap(curMap);
		
		int i, j , start, cnt, len, totLen, tmp;
		vector<int> res;
		if (words.size() < 1 || s.size() < words.size() * words[0].size())
		{
			return res;
		}
		
		for (i = 0; i < words.size(); i++)
		{
			initMap[words[i]]++;
		}			
		
		len = words[0].size();
		totLen = len * words.size();
		for (start = 0; start < len && start + totLen <= s.size(); start++)
		{
			curMap.clear();
			cnt = 0;
			for (i = start, j = start; i + totLen <= s.size() && j + len <= s.size();)
			{
				auto iter = initMap.find(s.substr(j, len));
				if (iter != initMap.end())
				{
					int &e = curMap[s.substr(j, len)];
					if (e < iter->second)
					{
						e++;
						j += len;
						
						if (++cnt == words.size())
						{
							res.push_back(i);
						}
						continue;
					}
				}
				
				if (i < j)
				{
					curMap[s.substr(i, len)]--;
					cnt--;
					i+= len;
				}
				else
				{
					i += len;
					j = i;
				}
			}
		}
		
		return res;
    }
};


/*
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
		unordered_map<string, int> initMap, curMap;
		initMap.max_load_factor(0.25);
		curMap.max_load_factor(0.25);
		initMap.reserve(512);
		curMap.reserve(512);
		
		int i, j , cnt, len;
		vector<int> res;
		if (words.size() < 1 || s.size() < words.size() * words[0].size())
		{
			return res;
		}
		
		for (i = 0; i < words.size(); i++)
		{
			initMap[words[i]]++;
		}			
		
		len = words[0].size();
		int totLen = len * words.size();
		for (i = 0; i + totLen <= s.size(); i++)
		{
			curMap.clear();
			cnt = 0;
			for (j = i; cnt < words.size(); j += len)
			{	
				int tmp = ++curMap[s.substr(j, len)];
				auto iter = initMap.find(s.substr(j, len));
				if (iter == initMap.end() || tmp > iter->second)
				{
					break;
				}
				cnt++;
			}
			
			if (cnt == words.size())
			{
				res.push_back(i);
			}
		}
		
		return res;
    }
};*/

int main()
{
	Solution S;
	string str = "barfoothefoobarman";
	vector<string> lst;
	lst.push_back("foo");
	lst.push_back("bar");
	vector<int> res = S.findSubstring(str, lst);
	
	for (auto e : res)
	{
		cout << e << " ";
	}
	cout << endl;
	return 0;
}