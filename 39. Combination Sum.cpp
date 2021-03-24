class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> cur;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0, cur, ans);
        return ans;
    }
private:
    void dfs(vector<int>& candidates, int target, int s, vector<int>& cur, vector<vector<int>>& ans) {
        int csum = 0;
        for (auto c:cur) {
            csum += c;
        }
        if (csum == target) {
            ans.push_back(cur);
            return;
        }
        
        for (int i = s; i < candidates.size(); ++i) {
            if (csum + candidates[i] > target) break;
            cur.push_back(candidates[i]);
            dfs(candidates, target, i, cur, ans);
            cur.pop_back();
        }
        
    }
};