/******************************************************************************************
LRU Cache
******************************************************************************************/

#include<bits/stdc++.h>

using namespace std;

#define pii pair<int, int>
#define mp make_pair

typedef long long ll;

class LRUCache{
public:
    LRUCache(int capacity) {
        cap = capacity;
		tot = 0;
		
		keyTimeMap.max_load_factor(0.25);
		keyTimeMap.reserve(512);
    }
    
    int get(int key) {
        auto iter = keyTimeMap.find(key);
		if (iter != keyTimeMap.end())
		{
			timeKeyMap.erase(iter->second.second);
			tot++;
			iter->second.second = tot;
			timeKeyMap.insert(mp(tot, key));
			
			return iter->second.first;
		}
		
		return -1;
    }
    
    void set(int key, int value) {
        auto iter = keyTimeMap.find(key);
		
		if (iter != keyTimeMap.end())
		{
			tot++;
			timeKeyMap.erase(iter->second.second);
			timeKeyMap.insert(mp(tot, key));
			iter->second.second = tot;
			iter->second.first = value;
		}
		else
		{
			tot++;
			if (keyTimeMap.size() == cap)
			{
				auto tmp = *timeKeyMap.begin();
				timeKeyMap.erase(timeKeyMap.begin());
				keyTimeMap.erase(tmp.second);
			}
			keyTimeMap.insert(mp(key, mp(value, tot)));
			timeKeyMap.insert(mp(tot, key));
		}
    }

	int cap;
	int tot;
	unordered_map<int, pii> keyTimeMap;
	map<int, int> timeKeyMap;
};

int main()
{
	// 2,[set(2,1),set(2,2),get(2),set(1,1),set(4,1),get(2)]
	int res = 0;
	LRUCache S(2);
	S.set(2, 1);
	S.set(2, 2);
	res = S.get(2);
	S.set(1, 1);
	S.set(4, 1);
	res = S.get(2);
	
	return 0;
}