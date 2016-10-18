/******************************************************************************************
Populating Next Right Pointers in Each Node II
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

 struct TreeLinkNode {
   int val;
   TreeLinkNode *left, *right, *next;
  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 };

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        
		if (!root)
		{
			return;
		}
		
		root->next = 0;
		
		if (root->right)
		{
			dfs(root->right, root);
		}
		if (root->left)
		{
			dfs(root->left, root);
		}	
    }
	
	void dfs(TreeLinkNode *cur, TreeLinkNode *parent)
	{
		TreeLinkNode *next = 0, *p;
		if (cur == parent->left && parent->right)
		{
			next = parent->right;
		}
		
		for (p = parent->next; p && !next; p = p->next)
		{
			if (p->left)
			{
				next = p->left;
			}
			else if (p->right)
			{
				next = p->right;
			}
		}
		
		cur->next = next;
		
		
		if (cur->right)
		{
			dfs(cur->right, cur);
		}
		if (cur->left)
		{
			dfs(cur->left, cur);
		}
	}
};

int main()
{
	Solution S;
	return 0;
}