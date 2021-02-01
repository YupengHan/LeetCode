class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> minpath(m, vector<int>(n, 0));
        vector<vector<bool>> visit(m, vector<bool>(n, false));
        
        int h = 0, v = 0;
        while(!visit[m-1][n-1]) {
            for (int i = h; i < n; ++i) {
                visit[v][i] = true;
                if (v-1 >= 0 && i-1 >= 0) {
                    minpath[v][i] = min(minpath[v-1][i],  minpath[v][i-1]) + grid[v][i];
                }
                else if (i-1 >= 0) {
                    minpath[v][i] = minpath[v][i-1] + grid[v][i];
                }
                else {
                    // cout << v << " " << i << endl;
                    minpath[v][i] = grid[v][i];
                }
            }
            for (int i = v; i < m; ++i) {
                visit[i][h] = true;
                if (h-1 >= 0 && i-1 >= 0) {
                    minpath[i][h] = min(minpath[i][h-1],  minpath[i-1][h]) + grid[i][h];
                }
                else if (i-1 >= 0) {
                    minpath[i][h] = minpath[i-1][h] + grid[i][h];
                }
                else {
                    // cout << i << " " << h << endl;
                    minpath[i][h] = grid[i][h];
                }
            }
            v++;
            h++;
            
        }

        // for (int i = 0; i < m; ++i) {
        //     for (int j = 0; j < n; ++j) {
        //         cout << "minpath[" << i << "][" << j << "] " << minpath[i][j] << endl;
        //     }
        // }
        return minpath[m-1][n-1];
        
    }
};























