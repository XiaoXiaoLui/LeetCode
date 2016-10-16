/******************************************************************************************
Recover Binary Search Tree
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


struct TreeNode {
 int val;
 TreeNode *left;
 TreeNode *right;
 TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void recoverTree(TreeNode* root) {
        bFind = false;
		pre = 0;
		find1(root);
		
		bFind = false;
		pre = 0;
		find2(root);
		
		swap(p1->val, p2->val);
    }
	
	void find1(TreeNode* p)
	{
		if (p->left)
		{
			find1(p->left);
		}
		
		if (!bFind && pre && p->val < pre->val)
		{
			p1 = pre;
			bFind = true;
			return;
		}
		pre = p;
		if (p->right)
		{
			find1(p->right);
		}
	}
	
	void find2(TreeNode* p)
	{
		if (p->right)
		{
			find2(p->right);
		}
		if (!bFind && pre && p->val > pre->val)
		{
			p2 = pre;
			bFind = true;
			return;
		}
		
		pre = p;
		if (p->left)
		{
			find2(p->left);
		}
	}
	
	bool bFind;
	TreeNode *p1, *p2;
	TreeNode *pre;
	vector<TreeNode*> wrongElements;
};

int main()
{
	Solution S;
	return 0;
}