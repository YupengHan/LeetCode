class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret;
        unordered_map<int, int> mymap;
        for (int i = 0; i < nums.size(); ++i) {
            std::map<int, int>::iterator copl;
            copl = mymap.find(nums[i]);
            if (copl != mymap.end()) {
                ret.push_back(i);
                ret.push_back(copl->second);
            }
            mymap[target - nums[i]] = i;
        }
        return ret;
    }
};