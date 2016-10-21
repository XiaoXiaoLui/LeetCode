/******************************************************************************************
Word Search II
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

const int DIR[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

struct Trie
{
	void init(int n, int m)
	{
		num = 1;
		maxNum = n;
		M = m;
		node.resize(maxNum + 10);
		e.resize(maxNum + 10);
		for (int i = 0; i < node.size(); i++)
		{
			e[i] = -1;
			node[i].resize(M + 5);
			for (int j = 0; j < M; j++)
			{
				node[i][j] = 0;
			}
		}
		
	}
	
	void add(const string &s, int id)
	{
		int i, u, idx;
		for (i = 0, u = 0; i < s.size(); i++)
		{
			idx = s[i] - 'a';
			if (!node[u][idx])
			{
				node[u][idx] = num++;
			}
			u = node[u][idx];
		}
		
		e[u] = id;
	}
	
	int next(int u, char ch)
	{
		return node[u][ch - 'a'];
	}
	
	vector<vector<int> > node;
	vector<int> e;
	int num;
	int M;
	int maxNum;
};

class Solution {
public:
    vector<string> findWords(vector<vector<char> >& board, vector<string>& words) {
        res.clear();
		if (!board.size() || !board[0].size())
		{
			return res;
		}
		
		n = board.size();
		m = board[0].size();
		
		int i, j, cnt;
		cnt = 0;
		for (auto &str : words)
		{
			cnt += str.size();
		}
		tr.init(cnt, 26);
		
		for (i = 0; i < words.size(); i++)
		{
			tr.add(words[i], i);
		}
	
		visit.resize(n);
		for (i = 0; i < n; i++)
		{
			visit[i].resize(m);
			fill_n(visit[i].begin(), m, false);
		}
	
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
			{
				dfs(board, words, mp(i, j), 0);
			}
		}
		
		
		
		return res;
    }
	
	void dfs(const vector<vector<char> >& board, const vector<string>& words, pii cur, int u)
	{
		int i, j, v, orgSize;
		v = tr.next(u, board[cur.first][cur.second]);
		if (!v)
		{
			return;
		}
		
		if (tr.e[v] != -1)
		{
			res.push_back(words[tr.e[v]]);
			tr.e[v] = -1;
		}
		
		pii nextPos;
		visit[cur.first][cur.second] = true;
		

		for (j = 0; j < 4; j++)
		{
			nextPos.first = cur.first + DIR[j][0];
			nextPos.second = cur.second + DIR[j][1];
			if (valid(nextPos) && !visit[nextPos.first][nextPos.second])
			{
				dfs(board, words, nextPos, v);
			}
		}
		
		visit[cur.first][cur.second] = false;
	}
	
	bool valid(pii pos)
	{
		return (pos.first >= 0 && pos.first < n && pos.second >= 0 && pos.second < m);
	}
	
	vector<string> res;
	vector<vector<bool> > visit;
	Trie tr;
	int n, m;	
};



int main()
{
	const string str[] = {"oaan","etae","ihkr","iflv"};
	
	int n, m;
	n = 4;
	m = str[0].size();
	vector<vector<char> > a(n);
	
	for (int i = 0; i < n; i++)
	{
		a[i].resize(m);
		for (int j = 0; j < m; j++)
		{
			a[i][j] = str[i][j];
		}
	}

	vector<string> b{"oath","pea","eat","rain"};
	Solution S;
	
	vector<string> c = S.findWords(a, b);
	return 0;
}