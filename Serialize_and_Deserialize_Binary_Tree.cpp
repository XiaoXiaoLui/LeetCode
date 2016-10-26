/******************************************************************************************
Serialize and Deserialize Binary Tree
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

  struct TreeNode {
      int val;
	  TreeNode()
	  {
		  
	  }
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
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
		string res;
		TreeNode *p;
		queue<TreeNode*> Q;
		Q.push(root);
		while (!Q.empty())
		{	
			auto q = Q.front();
			Q.pop();
			
			if (q)
			{
				res += num2Str(q->val);
				Q.push(q->left);
				Q.push(q->right);
			}
			else
			{
				res += '*';
			}
			
			res += ',';
		}
		
		return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
		TreeNode *root, *p;
		queue<TreeNode*> Q;
		
		int pos, offset;
		pos = data.find_first_of(',');
		if (data[pos - 1] == '*')
		{
			return 0;
		}
		
		root = new TreeNode(str2Num(data.substr(0, pos)));
		Q.push(root);
		
		offset = pos + 1;
		while (!Q.empty())
		{
			p = Q.front();
			Q.pop();
			
			pos = data.find_first_of(',', offset);
			if (data[pos - 1] == '*')
			{
				p->left = 0;
			}
			else
			{
				p->left = new TreeNode(str2Num(data.substr(offset, pos - offset)));
				Q.push(p->left);
			}
			offset = pos + 1;
			
			pos = data.find_first_of(',', offset);
			if (data[pos - 1] == '*')
			{
				p->right = 0;
			}
			else
			{
				p->right = new TreeNode(str2Num(data.substr(offset, pos - offset)));
				Q.push(p->right);
			}
			offset = pos + 1;
		}
		
		return root;
    }
	
	int str2Num(const string s)
	{
		int i = 0;
		int res, mul = 1;
		if (s[0] == '-')
		{
			mul = -1;
			i++;
		}
		
		for (res = 0; i < s.size(); i++)
		{
			res = res * 10 + s[i] - '0';
		}
		
		return res * mul;
	}
	
	string num2Str(int num)
	{
		int n = num;
		string res;
		if (n == 0)
		{
			res += '0';
			return res;
		}
		
		if (n < 0)
		{
			res += '-';
			n = -n;
		}
		
		string tmp;
		while (n)
		{
			tmp += (n % 10) + '0';
			n /= 10;
		}
		
		reverse(tmp.begin(), tmp.end());
		res += tmp;
		
		return res;
	}
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

int main()
{
	Codec S;
	TreeNode *p = new TreeNode(1);
	auto q = S.deserialize(S.serialize(p));
	return 0;
}