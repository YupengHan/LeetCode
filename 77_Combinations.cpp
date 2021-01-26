class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> comb(k,0);
        int count = 0;
        backtracking(ans, comb, count, 1, n, k);
        return ans;
    }
    void backtracking(vector<vector<int>>& ans, vector<int>& comb, int count, int pos, int n, int k) {
        cout << count << "   ";
        for (int i = 0; i < count; i++) {
            cout << comb[i];
        }
        cout << endl;
        if (count == k) {
            ans.push_back(comb);
            return;
        }
        if (count > k) {
            cout << "F*" << endl;
        }
        for (int i = pos; i <= n; ++i) {
            // count++;
            // comb[count] = i;
            comb[count++] = i;
            backtracking(ans, comb, count, i+1, n, k);
            count--;
        }
    }
};