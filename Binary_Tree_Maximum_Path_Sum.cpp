/******************************************************************************************
Binary Tree Maximum Path Sum
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
    int maxPathSum(TreeNode* root) {
		maxPath = -1e9;
		dfs(root);
		
		return maxPath;
    }
	
	int dfs(TreeNode *p)
	{
		if (!p)
		{
			return 0;
		}
		
		int leftMax, rightMax;
		
		leftMax = dfs(p->left);
		rightMax = dfs(p->right);
		
		int tmp = p->val;
		if (leftMax > 0)
		{
			tmp += leftMax;
		}
		if (rightMax > 0)
		{
			tmp += rightMax;
		}
		
		maxPath = max(maxPath, tmp);

		
		return max(0, max(leftMax, rightMax)) + p->val;
	}
	
	
	int maxPath;
};

int main()
{
	Solution S;
	return 0;
}