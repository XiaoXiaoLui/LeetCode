/******************************************************************************************
Insert Delete GetRandom O(1)
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


class RandomizedSet {
private:
	struct Node
	{
		Node(int x) : val(x), left(0), right(0), size(1)
		{
			
		}
		Node *left;
		Node *right;
		int val;
		int size;
	};
	
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        root = 0;
		srand(time(0));
    }
	
	~RandomizedSet()
	{
		delTree(root);
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
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int x) {	
		return insertNode(root, x);
    }
	
	bool insertNode(Node *&p, int x)
	{
		if (!p)
		{
			p = new Node(x);
			return true;
		}
		
		if (x == p->val)
		{
			return false;
		}
		
		int ret = false;
		if (x < p->val)
		{
			ret = insertNode(p->left, x);
		}
		else
		{
			ret = insertNode(p->right, x);
		}
		
		if (ret)
		{
			p->size++;
		}
		
		return ret;
	}
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int x) {
        return removeNode(root, x);
    }
	
	bool removeNode(Node *&p, int x)
	{
		if (!p)
		{
			return false;
		}
		
		int ret = false;
		if (x < p->val)
		{
			ret = removeNode(p->left, x);
			if (ret)
			{
				p->size--;
			}
		}
		else if (x > p->val)
		{
			ret = removeNode(p->right, x);
			if (ret)
			{
				p->size--;
			}
		}
		else
		{
			ret = true;
			Node *delNode = 0;
			if (!p->left)
			{
				delNode = p;
				p = p->right;
			}
			else
			{
				Node *q, *tq;
				for (q = p->left, tq = p; true; tq = q, q = q->right)
				{
					tq->val = q->val;
					tq->size--;
					if (!q->right)
					{
						break;
					}
				}
				
				delNode = q;
				if (q == tq->left)
				{
					tq->left = q->left;
				}
				else
				{
					tq->right = q->left;
				}
			}
			
			delete delNode;
		}
		
		return ret;
	}
    
    /** Get a random element from the set. */
    int getRandom() {
		if (!root)
		{
			return 0;
		}
		//srand(time(0));
		
        Node *p = root;
		int curIdx, randIdx, res;
		
		while (true)
		{
			randIdx = rand() % p->size;
			curIdx = p->left ? p->left->size : 0;
			if (randIdx == curIdx)
			{
				res = p->val;
				break;
			}
			else if (randIdx < curIdx)
			{
				p = p->left;
			}
			else
			{
				p = p->right;
			}
		}
		
		return res;
    }
	
private:

	
	Node *root;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */

int main()
{
	RandomizedSet S;
	S.insert(1);
	S.insert(1);
	S.insert(2);
	S.remove(3);
	cout << S.getRandom() << S.getRandom() << endl;
	return 0;
}