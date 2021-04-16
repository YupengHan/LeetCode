class TwoSum {
private:
    unordered_map<int, int> mMap;
    vector<int> mVec;
public:
    /** Initialize your data structure here. */
    TwoSum() {
    }
    
    /** Add the number to an internal data structure.. */
    void add(int number) {
        mVec.push_back(number);
        if (mMap.find(number) != mMap.end()) {
            mMap[number] = mMap[number]+1;
        }
        else {
            mMap[number] = 1;
        }
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        
        for (int i = 0; i < mVec.size(); ++i) {
            if (value == INT_MIN && mVec[i] > 0) continue; 
            if ( (mVec[i] == value - mVec[i] && mMap[value - mVec[i]] > 1) || 
                (mVec[i] != value - mVec[i] && mMap[value - mVec[i]]) ) {
                return true;
            }
        }
        return false;
    }
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */