

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> cur;
        vector<bool> visited(nums.size(), false);
        sort(nums.begin(), nums.end());
        dfs(nums, ret, cur, visited);
        return ret;
        
    }

    void dfs(vector<int>& nums, vector<vector<int>>& ret, vector<int>& cur, vector<bool>& visited) {
        if (cur.size() == nums.size()) ret.push_back(cur);

        for (int i = 0; i < nums.size(); ++i) {
            if (i != 0 && nums[i] == nums[i-1] && !visited[i-1]) continue;
            if (!visited[i]) {
                visited[i] = true;
                cur.push_back(nums[i]);
                dfs(nums, ret, cur, visited);
                cur.pop_back();
                visited[i] = false;
            }
        }
    }
};