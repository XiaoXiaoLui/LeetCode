/******************************************************************************************
Merge k Sorted Lists
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

void genRandom(vector<int>& a, int n, int low, int high)
{
	srand(time(0));
	for (int i = 0; i < n; i++)
	{
		a.push_back(rand() % (high - low) + low);
	}
}

void print(vector<int> &a)
{
	for (int i = 0; i < a.size(); i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

#define pii pair<int, int>
#define mp make_pair

typedef long long ll;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int i;
		ListNode *p, *head = 0, *tail = 0;
		for (i = 0; i < lists.size(); i++)
		{
			if (lists[i])
			{
				Q.push(mp(lists[i]->val, i));
				//lists[i] = lists[i]->next;
			}
		}
		
		pii tmp;
		while (!Q.empty())
		{
			tmp = Q.top();
			Q.pop();
			p = lists[tmp.second];
			lists[tmp.second] = p->next;
			p->next = 0;
			if (!head)
			{
				head = tail = p;
			}
			else
			{
				tail->next = p;
				tail = p;
			}
			
			if (lists[tmp.second])
			{
				Q.push(mp(lists[tmp.second]->val, tmp.second));
			}
		}
		
		return head;
    }
	
	priority_queue<pii, vector<pii>, greater<pii> > Q;
};

int main()
{
	Solution S;
	return 0;
}