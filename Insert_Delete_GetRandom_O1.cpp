/******************************************************************************************
Insert Delete GetRandom O(1)
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


class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        srand(time(0));

    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (hash.count(val) > 0)
		{
			return false;
		}
		array.push_back(val);
		hash[val] = (array.size() - 1);
		
		return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (hash.count(val) == 0)
		{
			return false;
		}
		int h = hash[val];
		hash[array.back()] = h;
		hash.erase(val);
		array[h] = array.back();
		array.pop_back();

		return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return array[rand() % array.size()];
    }
	
	vector<int> array;
	unordered_map<int, int> hash;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */

int main()
{
	RandomizedSet S;
	S.insert(1);
	S.insert(1);
	S.insert(2);
	S.remove(3);
	cout << S.getRandom() << S.getRandom() << endl;
	return 0;
}