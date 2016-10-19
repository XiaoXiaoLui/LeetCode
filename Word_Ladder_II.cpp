/******************************************************************************************
Word Ladder II
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
    vector<vector<string> > findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
		int s, t, n, sLen, i, j, k, u, v;
		n = wordList.size() + 2;
		s = n;
		t = 1;
		
		unordered_map<string, int> str2Num;
		INIT_UNORDER(str2Num);
		
		lst.clear();
		lst.push_back(beginWord);
		lst.insert(lst.end(), wordList.begin(), wordList.end());
		lst.push_back(endWord);
		
		str2Num[lst[0]] = 1;
		str2Num[lst[n - 1]] = n;
		for (i = 1; i  < lst.size() - 1; i++)
		{
			//if (lst[i] == begi)
			if (str2Num[lst[i]] == 0)
			{
				str2Num[lst[i]] = i + 1;
			}
		}
		
		vector<int> dist(n + 1, -1);
		pre.resize(n + 1);
		pre.clear();
		dist[s] = 0;
		queue<int> Q;
		Q.push(s);
		
		
		while (!Q.empty())
		{
			u = Q.front();
			Q.pop();
			
			if (u == t)
			{
				break;
			}
			
			int idx = u - 1;
			string tmp = lst[idx];
			for (i = 0; i < lst[idx].size(); i++)
			{
				if (i != 0)
				{
					tmp[i - 1] = lst[idx][i - 1];
				}
				
				for (j = 0; j < 26; j++)
				{
					
					if ('a' + j == lst[idx][i])
					{
						continue;
					}
					tmp[i] = 'a' + j;
					
					auto iter = str2Num.find(tmp);
					if (iter != str2Num.end())
					{
						v = iter->second;
						if (dist[v] == -1)
						{
							dist[v] = dist[u] + 1;
							Q.push(v);
							pre[v].push_back(u);
						}
						else if (dist[u] + 1 == dist[v])
						{
							pre[v].push_back(u);
						}
					}
				}

			}
		}
		
		ans.clear();
		
		if (dist[t] == -1)
		{
			return ans;
		}
		
		
		
		vector<string> path;
		dfs(t, path, s);
		
		return ans;
    }
	
	
	void dfs(int u, vector<string> &path, int t)
	{
		int i, v;
		path.push_back(lst[u - 1]);
		if (u == t)
		{
			ans.push_back(path);
			path.pop_back();
			return;
		}
		
		for (i = 0; i < pre[u].size(); i++)
		{
			v = pre[u][i];
			dfs(v, path, t);
		}
		
		path.pop_back();
	}

	
	vector<vector<string> > ans;
	vector<string> lst;
	vector<vector<int> > pre;
};

int main()
{
	Solution S;
	string a = "coder";
	string b = "goner";
	const string STRLST[] = {"lover","coder","comer","toner","cover","tower","coyer","bower","honer","poles","hover","lower","homer","boyer","goner","loner","boner","cower","never","sower","asian"};


	unordered_set<string> lst(STRLST, STRLST + sizeof(STRLST) / sizeof(string));
	
	vector<vector<string> > ans = S.findLadders(a, b, lst);
	
	for (int i = 0; i < ans.size(); i++)
	{
		for (int j = 0; j < ans[i].size(); j++)
		{
			cout << "\"" << ans[i][j] << "\", ";
		}
		cout << endl;
	}
	
	return 0;
}