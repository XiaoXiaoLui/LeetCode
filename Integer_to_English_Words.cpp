/******************************************************************************************
Integer to English Words
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

const static string STR1[] = {"Thousand", "Million", "Billion"};
const static string STR2[] = {"One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", 
							"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
const static string STR3[] = {"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

class Solution {
public:
    string numberToWords(int num) {
		if (!num)
		{
			return "Zero";
		}
		
        string res;
		//vector<string> tmp;
		int i = -1, r;
		
		while (num)
		{
			r = num % 1000;
			if (r)
			{
				if (i < 0)
				{
					res = get(r) + res;
				}
				else
				{
					res = get(r) + STR1[i] + " " + res;
				}
			}

			i++;
			num /= 1000;
		}
		
		res.erase(res.size() - 1);
		return res;
    }
	
	//1 <= n <= 999
	string get(int n)
	{
		string res;
		int q, r;
		q = n / 100;
		r = n % 100;
		if (q)
		{
			res += STR2[q - 1] + " Hundred ";
		}
		
		if (r)
		{
			if (r < 20)
			{
				res += STR2[r - 1] + " ";
			}
			else
			{
				q = r / 10;
				r = r % 10;
				
				res += STR3[q - 2] + " ";
				if (r)
				{
					res += STR2[r - 1] + " ";
				}
			}
		}
		
		return res;
	}
};

int main()
{
	Solution S;
	cout << S.numberToWords(100) << endl;
	cout << S.numberToWords(12345) << endl;
	cout << S.numberToWords(1234567) << endl;
	return 0;
}