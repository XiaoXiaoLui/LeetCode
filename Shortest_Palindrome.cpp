/******************************************************************************************
Shortest Palindrome
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


// kmp
class Solution {
public:
    string shortestPalindrome(string s) {
		if (s.size() < 2)
		{
			return s;
		}
		
        string rev = s;
		reverse(rev.begin(),rev.end());
		string str = s + "#" + rev;
		
		int n = 2*s.size() + 1;
		vector<int> next(n + 1);
		next[0] = -1;
		
		int i, j;
		for (i = 1, j = -1; i < n; i++)
		{
			for (; j != -1 && str[j + 1] != str[i]; j = next[j]);
			if (str[j + 1] == str[i])
			{
				j++;
			}
			next[i] = j;
		}
		
		int offset = next[n - 1];
		
		string res;
		res = rev.substr(0, s.size() - offset - 1);
		res += s;
		return res;
    }
};

/*
// overkill, general solution to find all max palindrome. 9ms, 37.43%
class Solution {
public:
    string shortestPalindrome(string s) {
		int n = s.size();
		if (n < 2)
		{
			return s;
		}
		
        vector<int> lenArray(2*n);
		vector<char> str(2*n);
		int lc, lr, r, c, i, maxPalRight = 0;
		
		for (i = 0; i < n; i++)
		{
			str[i + i] = s[i];
			str[i + i + 1] = '*';
		}
		
		// cal palindrome
		for (lc = -1, lr = -1, c = 0; c < 2*n - 1; c++)
		{
			r = c;
			if (lr > c)
			{
				r = min(lr, c + lenArray[2*lc - c]);
			}
			
			for (; r + 1 < 2*n - 1 && 2*c - (r + 1) >= 0 && str[r + 1] == str[2*c - r - 1]; r++);
			
			lenArray[c] = r - c;
			if (r == 2*c)
			{
				maxPalRight = r / 2;
			}
			
			if (r > lr)
			{
				lr = r;
				lc = c;
			}
		}
		
		string res;
		for (i = s.size() - 1; i > maxPalRight; i--)
		{
			res.push_back(s[i]);
		}
		for (i = 0; i <= maxPalRight; i++)
		{
			res.push_back(s[i]);
		}
		res += s.substr(maxPalRight + 1);
		
		return res;
    }
};
*/


int main()
{
	string a = "aacecaaa";
	Solution S;
	cout << S.shortestPalindrome(a) << endl;
	return 0;
}