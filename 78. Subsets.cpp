class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> cur;
        for (int i = 0; i <= nums.size(); ++i) {
            dfs(nums, i, 0, cur, ans);
        }
        return ans;
    }
private:
    void dfs(vector<int>& nums, int n, int s, vector<int>& cur, vector<vector<int>>& ans) {
        if (n == cur.size()) {
            ans.push_back(cur);
            return;
        }

        for (int i = s; i < nums.size(); ++i) {
            cur.push_back(nums[i]);
            dfs(nums, n, i+1, cur, ans);
            cur.pop_back();
        }
    }
};


