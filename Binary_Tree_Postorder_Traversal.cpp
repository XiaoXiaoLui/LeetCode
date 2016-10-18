/******************************************************************************************
Binary Tree Postorder Traversal
******************************************************************************************/

#include<bits/stdc++.h>

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
 #define pti pair<TreeNode*, int>
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<pti> S;
		vector<int> res;
		
		if (!root)
		{
			return res;
		}
		
		S.push(mp(root, 0));
		pti tmp;
		while (!S.empty())
		{
			tmp = S.top();
			//S.pop();
			if (tmp.second == 1)
			{
				res.push_back(tmp.first->val);
				S.pop();
			}
			else
			{
				S.top().second = 1;
				if (tmp.first->right)
				{
					S.push(mp(tmp.first->right, 0));
				}
				if (tmp.first->left)
				{
					S.push(mp(tmp.first->left, 0));
				}
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