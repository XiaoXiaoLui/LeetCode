
/*
propagation will takes linear time since (1, 1)~(n, 1)

*/
class SegmentTree2D
{
public:
	SegmentTree2D(int nn, int mm)
	{
		for (n = 8; n < nn; n *= 2);
		for (m = 8; m < mm; m *= 2);
		
		tr.resize(2*n + 1);
		lazy.resize(2*n + 1);
		int i;
		for (i = 1; i < n; i++)
		{
			tr[i].insert(tr[i].end(), 2, 0);
			lazy[i].insert(lazy[i].end(), 2, 0);
		}
		for (; i <= 2*n; i++)
		{
			tr[i].insert(tr[i].end(), 2*m + 1, 0);
			lazy[i].insert(lazy[i].end(), 2*m + 1, 0);
		}
	}
	
	int query(pii bottomLeft, pii topRight)
	{
		return rangeQuery(mp(1, 1), mp(1, 1), mp(n, m), bottomLeft, topRight);
	}
	
	void update(pii bottomLeft, pii topRight)
	{
		rangeUpdate(mp(1, 1), mp(1, 1), mp(n, m), bottomLeft, topRight, 1);
	}
	
private:	
	int rangeQuery(pii id, pii start, pii end, pii bottomLeft, pii topRight)
	{
		checkLazy(id, start, end);
		
		if (!intersect(start, end, bottomLeft, topRight))
		{
			return 0;
		}
		
		if (pointInRec(start, bottomLeft, topRight) && pointInRec(end, bottomLeft, topRight))
		{
			return tr[id.first][id.second];
		}
		
		int res = 0, res1, res2;
		pii id1, id2;
		id1 = id2 = id;
		if (start.first != end.first)
		{
			int mid = (start.first + end.first) / 2;
			id1.first = 2*id.first;
			id2.first = 2*id.first + 1;
			res1 = rangeQuery(id1, start, mp(mid, end.second), bottomLeft, topRight);
			res2 = rangeQuery(id2, mp(mid + 1, start.second), end, bottomLeft, topRight);
			res = res1 + res2;
		}
		else
		{
			int mid = (start.second + end.second) / 2;
			id1.second = 2*id.second;
			id2.second = 2*id.second + 1;
			res1 = rangeQuery(id1, start, mp(start.first, mid), bottomLeft, topRight);
			res2 = rangeQuery(id2, mp(start.first, mid + 1), end, bottomLeft, topRight);
			res = res1 + res2;
		}
		
		return res;
	}
	
	void checkLazy(pii id, pii start, pii end)
	{
		int &curLazy = lazy[id.first][id.second];
		if (curLazy)
		{
			tr[id.first][id.second] += curLazy * area(start, end);
			if (start.first != end.first)
			{
				lazy[id.first * 2][id.second] += curLazy;
				lazy[id.first * 2 + 1][id.second] += curLazy;
			}
			else if (start.second != end.second)
			{
				lazy[id.first][id.second * 2] += curLazy;
				lazy[id.first][id.second *2 + 1] += curLazy;
			}
			
			curLazy = 0;
		}
	}
	
	void rangeUpdate(pii id, pii start, pii end, pii bottomLeft, pii topRight, int val)
	{
		checkLazy(id, start, end);
		if (!intersect(start, end, bottomLeft, topRight))
		{
			return;
		}
		
		if (pointInRec(start, bottomLeft, topRight) && pointInRec(end, bottomLeft, topRight))
		{
			tr[id.first][id.second] += area(start, end) * val;
			if (start.first != end.first)
			{
				lazy[id.first * 2][id.second] += val;
				lazy[id.first * 2 + 1][id.second] += val;
			}
			else if (start.second != end.second)
			{
				lazy[id.first][id.second * 2] += val;
				lazy[id.first][id.second *2 + 1] += val;
			}
			
			return;
		}
		
		pii id1, id2;
		id1 = id2 = id;
		if (start.first != end.first)
		{
			int mid = (start.first + end.first) / 2;
			id1.first = 2*id.first;
			id2.first = 2*id.first + 1;
			rangeUpdate(id1, start, mp(mid, end.second), bottomLeft, topRight, val);
			rangeUpdate(id2, mp(mid + 1, start.second), end, bottomLeft, topRight, val);
			tr[id.first][id.second] = tr[id1.first][id1.second] + tr[id2.first][id2.second];
		}
		else
		{
			int mid = (start.second + end.second) / 2;
			id1.second = 2*id.second;
			id2.second = 2*id.second + 1;
			rangeUpdate(id1, start, mp(start.first, mid), bottomLeft, topRight, val);
			rangeUpdate(id2, mp(start.first, mid + 1), end, bottomLeft, topRight, val);
			tr[id.first][id.second] = tr[id1.first][id1.second] + tr[id2.first][id2.second];
		}
		
	}
	
	int area(pii bottomLeft, pii topRight)
	{
		return (topRight.second - bottomLeft.second + 1) * (topRight.first - bottomLeft.first + 1);
	}
	
	bool intersect(pii start, pii end, pii bottomLeft, pii topRight)
	{
		int left = start.first, right = end.first, down = start.second, up = end.second;
		
		return !(topRight.first < left || topRight.second < down || bottomLeft.first > right || bottomLeft.second > up);
	}
	
	bool pointInRec(pii p, pii start, pii end)
	{
		return p.first >= start.first && p.first <= end.first && p.second >= start.second && p.second <= end.second;
	}
	
	
	vector<vector<int> > tr;
	vector<vector<int> > lazy;
	int n, m;
};