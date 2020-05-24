class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        
        // cout << row << col;
        vector<int> time ((row*col), 100);
        
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                int time_map_id = i*grid[0].size() + j;
                if (grid[i][j] == 2) {
                    dfs(i,j,grid,time, 0);
                }
                else if (grid[i][j] == 0) {
                    time[time_map_id] = 0;
                }
                
            }
        }

        int ret_max = 0;
        for (int i = 0; i < row*col; i++) {
            // cout << "i: " << i << "time[i]: " << time[i] << endl;
            // if(time[i] != 100) {
            //     ret_max = max(ret_max, time[i]);
            // }
            ret_max = max(ret_max, time[i]);
            
        }

        if (ret_max == 100) {
            return -1;
        }
        
        return ret_max;
        
        
        
    }

    void dfs(int i, int j, vector<vector<int>>& grid, vector<int>& time, int level) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0) {
            return;
        }
        
        int time_map_id = i*grid[0].size() + j;
        // cout << time_map_id << endl;
        if (time[time_map_id] > level) {
            time[time_map_id] = level;
            dfs(i-1,j,grid,time,level+1);
            dfs(i,j-1,grid,time,level+1);
            dfs(i+1,j,grid,time,level+1);
            dfs(i,j+1,grid,time,level+1);    
        }
    }
};