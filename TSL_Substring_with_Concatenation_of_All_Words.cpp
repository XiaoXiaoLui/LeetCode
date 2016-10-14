/******************************************************************************************
Substring with Concatenation of All Words
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

#define pii pair<int, int>
#define mp make_pair

typedef long long ll;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
		multiset<string> initSet, S;
		int i, j, k, pos, len;
		vector<int> res;
		if (words.size() < 1)
		{
			return res;
		}
		
		len = words[0].size();
		initSet.insert(words.begin(), words.end());
			
		multiset<string>::iterator iter;
		for (i = 0; i + words.size() * len <= s.size(); i++)
		{
			S = initSet;
			
			for (j = i; !S.empty(); j += len)
			{
				iter = S.find(s.substr(j, len));
				if (iter == S.end())
				{
					break;
				}
				S.erase(iter);
			}
			if (S.empty())
			{
				res.push_back(i);
			}
		}
		
		return res;
    }
};

int main()
{
	Solution S;
	return 0;
}