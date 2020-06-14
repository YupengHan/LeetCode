class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int mmax = 0;
        unordered_set<int> md;
        for (auto x:nums) {
            md.insert(x);
            mmax = max(mmax, x);
        }
        if (mmax != INT_MAX) {
            mmax += 1;
        }
        
        
        for (int i = 1; i <= mmax; i++) {
            if (!md.count(i)) {
                return i;
            }
            else {
                md.erase(i);
            }
            
        }
        return -1;
        
    }
};