class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> cur;
        sort(candidates.begin(), candidates.end());
        dfs(ans, cur , candidates, 0, target);
        return ans;
    }

    void dfs(vector<vector<int>>& ans, vector<int>& cur, vector<int>& candidates, int startIdx, int target) {
        if (target == 0) {
            ans.push_back(cur);
            return;
        }

        for (int i = startIdx; i < candidates.size(); ++i) {
            if (i > startIdx && candidates[i] == candidates[i-1]) continue;
            int cTar = target - candidates[i];
            if (cTar < 0) break;
            cur.push_back(candidates[i]);
            dfs(ans, cur, candidates, i+1, cTar);
            cur.pop_back();
        }
    }
};