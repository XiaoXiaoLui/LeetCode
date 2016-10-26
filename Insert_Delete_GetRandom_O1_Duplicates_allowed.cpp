/******************************************************************************************
Insert Delete GetRandom O(1) - Duplicates allowed
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

class RandomizedCollection {
public:

    /** Initialize your data structure here. */
    RandomizedCollection() {
        srand(time(0));
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        auto iter = hash.insert(mp(val, array.size()));
		array.push_back(iter);
		
		return true;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
		auto iter = hash.find(val);
        if (iter == hash.end())
		{
			return false;
		}
		
		int h = iter->second;
		array.back()->second = h;
		array[h] = array.back();
		hash.erase(iter);
		array.pop_back();
		
		return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return array[rand() % array.size()]->first;
    }
	
	unordered_multimap<int, int> hash;
	vector<unordered_multimap<int, int>::iterator> array;
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */


int main()
{
	RandomizedCollection S;
	S.insert(1);
	S.insert(1);
	S.insert(2);
	S.remove(3);
	cout << S.getRandom() << S.getRandom() << endl;
	return 0;
}