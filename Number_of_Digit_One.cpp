/******************************************************************************************
Number of Digit One
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

class Solution {
public:
    int countDigitOne(int n) {
        int left, right, res, p, cur;
		
		for (left = right = res = 0, p = 1; n; n /= 10)
		{
			left = n / 10;
			cur = n % 10;
			
			if (cur > 1)
			{
				res += (left + 1) * p;
			}
			else if (cur == 1)
			{
				res += left * p + right + 1;
			}
			else
			{
				res += left * p;
			}
			
			
			right += cur * p;
			p *= 10;
			
		}
		
		return res;
    }
};

/*
class Solution {
public:
    int countDigitOne(int n) {
		if (!n)
		{
			return 0;
		}
		
        vector<int> pow10(M);
		vector<int> sum1(M);
		vector<int> sum2(M);
		vector<int> a(M);
		
		int i, tmp, res, m;
		pow10[0] = 1;
		sum1[0] = n % 10;
		a[0] = n % 10;
		n /= 10;
		m = 1;
		while (n)
		{
			pow10[m] = pow10[m - 1] * 10;
			tmp = n % 10;
			a[m] = tmp;
			sum1[m] = sum1[m - 1] + tmp * pow10[m];
			n /= 10;
			m++;
		}
		
		sum2[m] = 0;
		for (i = m - 1; i >= 0; i--)
		{
			sum2[i] = sum2[i + 1] * 10 + a[i];
		}
		
		res = 0;
		for (i = 0; i < m; i++)
		{
			if (a[i] > 1)
			{
				res += (sum2[i + 1] + 1) * pow10[i];
			}
			else if (a[i] == 1)
			{
				res += sum2[i + 1] * pow10[i] + (i > 0 ? sum1[i - 1] + 1 : 1);
			}
			else
			{
				res += sum2[i + 1] * pow10[i];
			}
		}
		
		return res;
    }
	
	const static int M = 32;
};*/


int main()
{
	Solution S;
	cout << S.countDigitOne(13) << endl;
	return 0;
}