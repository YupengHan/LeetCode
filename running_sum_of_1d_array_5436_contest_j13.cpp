class Solution {
public:
    static bool sortbysec(pair<int, int>&a, pair<int, int>&b){
        return (a.second < b.second);
    }
    vector<int> runningSum(vector<int>& nums) {
        int cur = 0;
        vector<int> ret;
        for (size_t i = 0; i < nums.size(); i++) {
            cur += nums[i];
            ret.insert(ret.end(),cur);
        }
        return ret;
    }
};