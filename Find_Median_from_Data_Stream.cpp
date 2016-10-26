/******************************************************************************************
Find Median from Data Stream
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

class MedianFinder {
public:
    // Adds a number into the data structure.
    void addNum(int num) {
		if (!leftHeap.size() || leftHeap.top() >= num)
		{
			leftHeap.push(num);
			if (leftHeap.size() > rightHeap.size() + 1)
			{
				int tmp = leftHeap.top();
				leftHeap.pop();
				rightHeap.push(tmp);
			}
		}
		else
		{
			rightHeap.push(num);
			if (rightHeap.size() > leftHeap.size())
			{
				int tmp = rightHeap.top();
				rightHeap.pop();
				leftHeap.push(tmp);
			}
		}
    }

    // Returns the median of current data stream
    double findMedian() {

        if (leftHeap.size() > rightHeap.size())
		{
			return leftHeap.top();
		}
		else
		{
			return (leftHeap.top() + rightHeap.top()) / 2.0;
		}
    }
	
	priority_queue<int> leftHeap;
	priority_queue<int, vector<int>, greater<int> > rightHeap;
};


int main()
{
	MedianFinder S;
	return 0;
}