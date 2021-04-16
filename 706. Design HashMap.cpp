class MyHashMap {
private:
    vector<vector<pair<int, int>>> myOpenHash;
    int vSize;
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        vSize = 100000;
        myOpenHash.resize(vSize);
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        int l1Idx = key % vSize;
        for (int i = 0; i < myOpenHash[l1Idx].size(); ++i) {
            auto p = myOpenHash[l1Idx][i];
            int k = p.first, v = p.second;
            if (k == key) {
                myOpenHash[l1Idx].erase(myOpenHash[l1Idx].begin()+i);
                break;
            }
        }

        myOpenHash[l1Idx].push_back(make_pair(key, value));
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int l1Idx = key % vSize;
        for (auto p : myOpenHash[l1Idx]) {
            int k = p.first, v = p.second;
            if (k == key) return v;
        }
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int l1Idx = key % vSize;
        for (int i = 0; i < myOpenHash[l1Idx].size(); ++i) {
            auto p = myOpenHash[l1Idx][i];
            int k = p.first, v = p.second;
            if (k == key) {
                myOpenHash[l1Idx].erase(myOpenHash[l1Idx].begin()+i);
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */