class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> mySet;
        for (auto n1:nums1) {
            mySet.push(n1);
        }
        vector<int> ret;
        for (auto n2:nums2) {
            if (mySet.find(n2) != mySet.end()) {
                ret.push_back(n2);
            }
        }

        return ret;
    }
};