class Solution {
private:
    void helper(vector<int>& candidates, vector<bool>& visited, int target, vector<int>& cur_list, set<vector<int>>&  ans_set, int snidx) {
        if (target == 0) {
            ans_set.insert(cur_list);
        }

        for (int i = snidx; i < candidates.size(); ++i) {
            if(!visited[i]) {
                if (target >= visited[i]) {
                    visited[i] = true;
                    cur_list.push_back(candidates[i]);
                    helper(candidates, visited, target-candidates[i], cur_list, ans_set, i);
                    cur_list.pop_back();
                    visited[i] = false;
                }
            }
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<bool> visited(candidates.size(), false);
        set<vector<int>> ans_set;
        vector<int> cur_list = {};
        int snidx = 0;
        helper(candidates, visited, target, cur_list, ans_set, snidx);
        vector<vector<int>> ans;
        for (auto a : ans_set) {
            ans.push_back(a);
        }
        return ans;
    }
};