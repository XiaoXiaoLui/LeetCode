/******************************************************************************************
Word Ladder II
******************************************************************************************/

/*
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
#include <ctime>*/
#include<bits/stdc++.h>

using namespace std;

#define pii pair<int, int>
#define mp make_pair

typedef long long ll;

class Solution {
public:
    vector<vector<string> > findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
        
		unordered_set<string>::iterator iter1, iter2;
		
		int s, t, n, sLen, i, j, k, u, v;
		n = wordList.size() + 2;
		s = n;
		t = 1;
		
		graph.resize(n + 1);
		graph.clear();
		
		
		lst.clear();
		lst.push_back(beginWord);
		lst.insert(lst.end(), wordList.begin(), wordList.end());
		lst.push_back(endWord);
		
		
		// cal hash
		sLen = beginWord.size();
		exp.clear();
		exp.resize(beginWord.size() + 1);
		hash.clear();
		hash.resize(n + 1);
		set<pii> S;
		set<pii>::iterator siter;
		for (i = 1, exp[0] = 1; i < exp.size(); i++)
		{
			exp[i] = (exp[i - 1] * 26) % MOD;
		}
		for (i = 0; i < lst.size(); i++)
		{
			hash[i + 1] = calHash(lst[i]);
			S.insert(mp((int)hash[i + 1], i + 1));
		}
		
		int curHash, tmpHash, nextHash;
		for (i = 0; i < lst.size(); i++)
		{
			curHash = hash[i + 1];
			for (j = 0; j < sLen; j++)
			{
				for (k = 0; k < 26; k++)
				{
					if ((char)('a' + k) != lst[i][j])
					{
						nextHash = ((curHash + (k + 'a' - lst[i][j])*exp[j]) % MOD + MOD) % MOD;
						pii tmp = mp((int)nextHash, 0);
						for (siter = S.lower_bound(tmp); siter != S.end() && siter->first == nextHash; siter++)
						{
							if (isAdj(lst[i], lst[siter->second - 1]))
							{
								graph[i + 1].push_back(siter->second);
								//graph[siter->second].push_back(i + 1);
							}
						}
					}
				}
			}
		}
		
		
		// dijkstra
		vector<int> dist(n + 1, -1);
		pre.resize(n + 1);
		pre.clear();
		dist[s] = 0;
		S.clear();
		S.insert(mp(0, s));
		
		
		while (!S.empty())
		{
			u = S.begin()->second;
			S.erase(S.begin());
			
			if (u == t)
			{
				break;
			}
			
			for (i = 0; i < graph[u].size(); i++)
			{
				v = graph[u][i];
				if (dist[v] == -1 || dist[u] + 1 < dist[v])
				{
					if (dist[v] != -1)
					{
						S.erase(mp(dist[v], v));
					}
					
					dist[v] = dist[u] + 1;
					S.insert(mp(dist[v], v));
					
					pre[v].clear();
					pre[v].push_back(u);
				}
				else if (dist[u] + 1 == dist[v])
				{
					pre[v].push_back(u);
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
	
	ll calHash(const string &str)
	{
		int i;
		ll res = 0;
		for (i = 0; i < str.size(); i++)
		{
			res = (res + (str[i] - 'a')*exp[i]) % MOD;
		}
		return res;
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
	
	bool isAdj(const string &a, const string &b)
	{
		int cnt = 0, i;
		for (i = 0; i < a.size(); i++)
		{
			if (a[i] != b[i])
			{
				cnt++;
				if (cnt > 1)
				{
					break;
				}
			}
		}
		
		return cnt == 1;
	}
	
	vector<vector<string> > ans;
	vector<string> lst;
	vector<vector<int> > graph;
	vector<vector<int> > pre;
	vector<ll> hash;
	vector<ll> exp;
	const ll MOD = 1e9 + 7;
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