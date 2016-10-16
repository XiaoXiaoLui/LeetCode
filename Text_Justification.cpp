/******************************************************************************************
Text Justification
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
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        string tmp;
		vector<string> res;
		int i, j, k, q, r, num, curLen, spaceLen;
		
		i = 0;
		while (i < words.size())
		{
			num = 1;
			curLen = words[i].size(); 
			for (j = i + 1; j < words.size() && curLen + words[j].size() + 1 <= maxWidth; j++)
			{
				 num++;
				 curLen += words[j].size() + 1;
			}
			
			if (j == words.size())
			{
				tmp = words[i];
				for (k = i + 1; k < words.size(); k++)
				{
					tmp.append(1, ' ');
					tmp += words[k];
				}
				tmp.append(maxWidth - tmp.size(), ' ');
				res.push_back(tmp);
				break;
			}
			
			if (num == 1)
			{
				tmp = words[i];
				tmp.append(maxWidth - tmp.size(), ' ');
				res.push_back(tmp);
			}
			else
			{
				tmp = words[i];
				num--;
				spaceLen = (maxWidth - curLen + num);
				q = spaceLen / num;
				r = spaceLen % num;
				for (k = i + 1; k < j; k++)
				{
					if (r)
					{
						tmp.append(q + 1, ' ');
						r--;
					}
					else
					{
						tmp.append(q, ' ');
					}
					tmp += words[k];
				}
				res.push_back(tmp);
			}
			
	
			i = j;
		}
		
		return res;
    }
};

int main()
{
	Solution S;
	return 0;
}