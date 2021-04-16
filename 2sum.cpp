class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> myMap;
        for (int i = 0; i < nums.size(); ++i) {
            myMap[target-nums[i]] = i;
            if (myMap.count(nums[i])) {
                return {i, myMap[nums[i]]};
            }
            
        }
        return {};
    }
};