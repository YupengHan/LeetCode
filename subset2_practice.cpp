class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> cur;
        dfs(nums, 0, cur, ans);
        return ans;
    }

    void dfs(vector<int>& nums, int s, vector<int>& cur, vector<vector<int>>& ans) {
        cout << s << " ";
        for (auto c : cur) {
            cout << c << " ";
        }
        cout << endl;
        ans.push_back(cur);

        for (int i = s; i < nums.size(); ++i) {
            if (i>s && nums[i] == nums[i-1]) {
                
                // cout << "not have: " << s << " ";
                cout << "not have: ";
                for (auto c : cur) {
                    cout << c << " ";
                }
                cout << nums[i] << " ";
                cout << endl;
                continue;
            }

            cur.push_back(nums[i]);
            dfs(nums, i+1, cur, ans);
            cur.pop_back();
        }
    }
};