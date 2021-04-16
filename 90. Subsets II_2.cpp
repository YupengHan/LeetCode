class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> cur;
        dfs(nums, ans, cur, 0);
        return ans;
    }
    void dfs(vector<int>& nums, vector<vector<int>>& ans, vector<int>& cur, int start) {
        ans.push_back(cur);
        for (int i = start; i < nums.size(); ++i) {
            if (i > start && nums[i] == nums[i-1]) continue;
            cur.push_back(nums[i]);
            dfs(nums, ans, cur, i+1);
            cur.pop_back();
        }
    }
};