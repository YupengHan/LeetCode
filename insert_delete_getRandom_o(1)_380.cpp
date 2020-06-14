class RandomizedSet {
private:
    unordered_map<int, int> mmap;
    vector<int> mnums;
    int msize;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        msize = 0;
        // cout << msize << endl;
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (!mmap.count(val)) {
            mmap[val] = msize;
            mnums.insert(mnums.end(), val);
            msize++;
            // cout << msize << endl;
            return true;  
        }
        return false;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (mmap.count(val)) {
            
            // cout << 29 << msize << endl;
            int l_num = mnums[mnums.size()-1];
            int l_id = mmap[l_num];
            int v_id = mmap[val];
            
            mmap[l_num] = v_id;
            mmap.erase(val);

            mnums.pop_back();
            mnums[v_id] = l_num;
            msize--;
            // cout << msize << " " << mmap.size() << endl;

            return true;
            
        }
        else {
            return false;
        }
        
        
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        if (msize <= 0) {
            return -1;
        }
        int randid = rand() % msize;
        return mnums[randid];
        
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */