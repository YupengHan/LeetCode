class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ret;
        for (int i = 0; i < n; i++) {
            ret.insert(ret.end(), nums[i*2]);
            ret.insert(ret.end(), nums[i*2+1]);
        }
        return ret;
        
    }
};