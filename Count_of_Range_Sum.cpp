/******************************************************************************************
Count of Range Sum
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

struct BinaryTree
{
	struct Node
	{
		Node(ll x) : val(x), left(0), right(0), size(1)
		{
			
		}
		Node *left;
		Node *right;
		ll val;
		int size;
	};
	
	BinaryTree() : root(0)
	{
		
	}
	
	~BinaryTree()
	{
		delTree(root);
		root = 0;
	}
	
	void delTree(Node *p)
	{
		if (p)
		{
			delTree(p->left);
			delTree(p->right);
			delete p;
		}
	}
	
	void insert(ll x)
	{
		if (!root)
		{
			root = new Node(x);
			return;
		}
		
		Node *p, *tp;
		p = root;
		while (p)
		{
			tp = p;
			p->size++;
			if (x < p->val)
			{
				p = p->left;
			}
			else if (x > p->val)
			{
				p = p->right;
			}
			else
			{
				return;
			}
		}
		
		if (x < tp->val)
		{
			tp->left = new Node(x);
		}
		else
		{
			tp->right = new Node(x);
		}
	}
	
	int countNum(ll x)
	{
		Node *p = root;
		int cnt = 0;
		while (p)
		{
			if (x > p->val)
			{
				cnt += (p->right ? p->size - p->right->size: p->size);
				p = p->right;
			}
			else if (x < p->val)
			{
				p = p->left;
			}
			else
			{
				cnt += (p->right ? p->size - p->right->size: p->size);
				break;
			}
		}
		
		return cnt;
	}
	
	Node *root;
};

/*
lower <= sum - x <= upper
sum - upper <= x <= sum - lower
*/
class Solution {
public:
    int countRangeSum(vector<int>& a, int lower, int upper) {
        
		BinaryTree tr;
		ll sum, left, right;
		int res, leftCnt, rightCnt;
		sum = 0LL;
		res = 0;
		tr.insert(0LL);
		for (auto num : a)
		{
			sum += num;
			left = sum - upper;
			right = sum - lower;
			leftCnt = tr.countNum(left - 1);
			rightCnt = tr.countNum(right);
			res += rightCnt - leftCnt;
			
			tr.insert(sum);
		}
		
		return res;
    }
};

int main()
{
	vector<int> a{-2147483647,0,-2147483647,2147483647};
	int lower = -564;
	int upper = 3864;
	Solution S;
	cout << S.countRangeSum(a, lower, upper) << endl;
	return 0;
}