// class Solution {
// private:
//     void permute(vector<int>& nums, set<vector<int>>& ans, int level) {
//         if(level == nums.size()-1 ) {
//             ans.insert(nums);
//         }
//         for (int i = level; i < nums.size(); ++i) {
//             swap(nums[i], nums[level]);
//             permute(nums, ans, level+1);
//             swap(nums[level], nums[i]);
//         }
//     }
// public:
//     vector<vector<int>> permuteUnique(vector<int>& nums) {
//         set<vector<int>> ans_set;
//         permute(nums, ans_set, 0);
//         vector<vector<int>> ans;
//         for (auto a : ans_set) {
//             ans.push_back(a);
//         }
//         return ans;
//     }
// };

// 可以不使用set, 通过先排序，再跳过重复的方法