class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m_map;
        for (int i = 0; i < nums.size(); ++i) {
            int complem = target - nums[i];
            if (m_map.find(complem) != m_map.end()) {
                return {i, m_map[complem]};
            }
            m_map[nums[i]] = i;
        }

        return {};
    }
};