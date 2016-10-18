/******************************************************************************************
Copy List with Random Pointer
******************************************************************************************/

#include<bits/stdc++.h>

using namespace std;

#define pii pair<int, int>
#define mp make_pair

typedef long long ll;

 struct RandomListNode {
      int label;
      RandomListNode *next, *random;
      RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
  };

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        
		RandomListNode *res, *p, *q, *tmp;
		res = 0;
		
		ptMap.clear();
		ptMap.max_load_factor(0.25);
		ptMap.reserve(512);
		for (p = head, q = 0; p; p = p->next, q = tmp)
		{
			tmp = new RandomListNode(p->label);
			if (!q)
			{
				res = q = tmp;
			}
			else
			{
				q->next = tmp;
			}
			if (p->random)
			{
				ptMap[p->random].push_back(tmp);
			}
			else
			{
				tmp->random = 0;
			}
		}
		
		for (p = head, q = res; p; p = p->next, q = q->next)
		{
			for (auto r : ptMap[p])
			{
				r->random = q;
			}
		}
		
		return res;
    }
	
	unordered_map<RandomListNode*, vector<RandomListNode*> > ptMap;
};

int main()
{
	Solution S;
	return 0;
}