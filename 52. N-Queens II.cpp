class Solution {
public:
    int totalNQueens(int n) {
        vector<vector<string>> ans;
        if (n < 0) return ans;
        vector<int> cols;
        dfs(ans, cols, n);
        return ans.size();
    }

private:
    void dfs(vector<vector<string>>& ans, vector<int>& cols, int n) {
        if (cols.size() == n) {
            ans.push_back(drawChessBorad(cols));
            return;
        }

        for (int colIdx = 0; colIdx < n; ++colIdx) {
            if (!isValid(cols, colIdx)) {
                continue;
            }
            cols.push_back(colIdx);
            dfs(ans, cols, n);
            cols.pop_back();
        }
    }
    vector<string> drawChessBorad(vector<int> cols) {
        vector<string> ret;
        for (int i = 0; i < cols.size(); ++i) {
            string sb;
            for (int j = 0; j < cols.size(); ++j) {
                sb += (j == cols[i]) ? "Q" : ".";
            }
            ret.push_back(sb);
        }
        return ret; 
    }
    bool isValid(vector<int> cols, int column) {
        int row = cols.size();
        for (int i = 0; i < row; ++i) {
            if (cols[i] == column) return false;
            if (i + cols[i] == row + column) return false;
            if (i - cols[i] == row - column) return false;
        }
        return true;
    }
};