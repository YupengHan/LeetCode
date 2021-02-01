// 为啥我觉得这道题目是BFS
class Solution {
private:
    vector<int> direction{-1, 0, 1, 0, -1};
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        // vector<vector<bool>> visit(m, vector<bool>(n, false));
        vector<vector<int>> ret(m, vector<int>(n, -1));
        queue<pair<int, int>> mq;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    ret[i][j] = 0;
                    mq.push(make_pair(i,j));
                }
            }
        }
        int level = 0;
        while(!mq.empty()) {
            int num = mq.size();
            level++;
            while(num--) {
                auto [x,y] = mq.front();
                mq.pop();

                for (int i = 0; i < 4; ++i) {
                    int nx = x + direction[i], ny = y + direction[i+1];
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                        if (ret[nx][ny] == -1) {
                            ret[nx][ny] = level;
                            mq.push(make_pair(nx, ny));
                        }
                    }
                }
            }
        }
        return ret;
    }
};

















// 转换四个方向为右下和左上两个loop














