/******************************************************************************************
Reverse Nodes in k-Group
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *tail, *curHead, *curTail, *p = head, *q;
		int curLen;
		for (head = tail = curHead = curTail = 0, curLen = 0; p; p = q)
		{
			q = p->next;
			if (curHead == 0)
			{
				curHead = curTail = p;
				p->next = 0;
			}
			else
			{
				p->next = curHead;
				curHead = p;
			}
			
			curLen++;
			if (curLen == k)
			{
				curLen = 0;
				if (head == 0)
				{
					head = curHead;
					tail = curTail;
				}
				else
				{
					tail->next = curHead;
					tail = curTail;
				}
				curHead = curTail = 0;
			}
		}
		

		p = curHead;
		for (curHead = curTail = 0; p; p = q)
		{
			q = p->next;
			if (curHead == 0)
			{
				curHead = curTail = p;
				p->next = 0;
			}
			else
			{
				p->next = curHead;
				curHead = p;
			}
		}
			
		if (head == 0)
		{
			head = curHead;
			tail = curTail;
		}
		else
		{
			tail->next = curHead;
			tail = curTail;
		}
		return head;
    }
};

int main()
{
	Solution S;
	return 0;
}