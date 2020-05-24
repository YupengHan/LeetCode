// class Solution {
// public:
//     int numIslands(vector<vector<char>>& grid) {
//         if (grid.empty()) {
//             return 0;
//         }
//         int count = 0;

//         int row = grid.size();
//         int col = grid[0].size();
//         for (int i = 0; i < row; ++i) {
//             for (int j = 0; j < col; ++j) {
//                 count += grid[i][j]- '0';
//                 dfs(grid, i, j, row, col);
//             }
//         }
//         return count;


//     }
// private:
//     void dfs(vector<vector<char>>&grid, int x, int y, int m, int n) {
//         if (x < 0 || y < 0 || x > m || y > n || grid[x][y] == '0') return;
//         grid[x][y] = '0';
//         dfs(grid, x-1, y, m, n);
//         dfs(grid, x, y-1, m, n);
//         dfs(grid, x+1, y, m, n);
//         dfs(grid, x, y+1, m, n);
//     }
// };



// class Solution {
// public:
    
//     // struct to hold info about a cell
//     struct cell {
//         int row;
//         int column;
//     };
    
//     // this function connects all the possible lands together to form an island
//     void connectIsland(int i, int j, vector<vector<char>>& grid, vector<vector<char>>& claimed)
//     {
//         // a queue of lands that need to be visited
//         // and marked as claimed since it belongs to the current island
//         queue<cell> q;
//         cell c;
//         c.row = i;
//         c.column = j;
//         claimed[c.row][c.column] = 'c'; // mark this land as claimed 'c'
        
//         q.push(c);
        
//         // keep claiming lands for the current island by claiming
//         // those neighboring lands and explore their neigbors too
//         while (q.empty() == false)
//         {
//             c = q.front();
//             q.pop();
//             i = c.row;
//             j = c.column;
            
//             // explore all the 4 neighbors of the current land to see
//             // if they can be claimed
//             if (i-1 >= 0 && grid[i-1][j] == '1' && 
//                 claimed[i-1][j] != 'c')   // only claim this neighboring land if it wasn't claimed already
//             {
//                 c.row = i-1;
//                 c.column = j;
//                 q.push(c);
//                 claimed[c.row][c.column] = 'c'; // mark this land as claimed 'c'
//             }
            
//             if (i+1 < grid.size() && grid[i+1][j] == '1' && claimed[i+1][j] != 'c')
//             {
//                 c.row = i+1;
//                 c.column = j;
//                 q.push(c);
//                 claimed[c.row][c.column] = 'c'; // mark this land as claimed 'c'
//             }
            
//             if (j-1 >= 0 && grid[i][j-1] == '1' && claimed[i][j-1] != 'c')
//             {
//                 c.row = i;
//                 c.column = j-1;
//                 q.push(c);
//                 claimed[c.row][c.column] = 'c'; // mark this land as claimed 'c'
//             }
            
//             if (j+1 < grid[0].size() && grid[i][j+1] == '1' && claimed[i][j+1] != 'c')
//             {
//                 c.row = i;
//                 c.column = j+1;
//                 q.push(c);
//                 claimed[c.row][c.column] = 'c'; // mark this land as claimed 'c'
//             }
//         }
//     }
        
//     int numIslands(vector<vector<char>>& grid) {
//         // if the grid is empty, return 0
//         if (grid.size() == 0 || grid[0].size() == 0)
//             return 0;
        
//         int numOfIslands = 0;
//         vector<vector<char>> claimed = grid;
            
//         // loop through each cell in the grid to find all the islands
//         for (int i = 0; i < grid.size(); i++)
//         {
//             for (int j = 0; j < grid[0].size(); j++)
//             {
//                 // if we have discovered a new island, call connectIsland
//                 // to connect all its lands together
//                 if (claimed[i][j] != 'c' && grid[i][j] == '1')
//                 {
//                     numOfIslands++;
//                     connectIsland(i,j, grid, claimed);
//                 }
//             }
//         }
        
//         return numOfIslands;
//     }
// };



/*
    Another round
*/
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {

        if (grid.empty()) {
            return 0;
        }
        
        // cout << grid[0][0] << endl;
        int row_len = grid.size();
        int col_len = grid[0].size();

        int cnt = 0;
        for (int row_i = 0; row_i < row_len; row_i++) {
            for (int col_j = 0; col_j < col_len; col_j++) {
                if (grid[row_i][col_j] == '1') {
                    // cout << "ADD " << row_i << " " << col_j << endl;
                    dfs(grid, row_i, col_j);
                    cnt++;
                }
                
            }
            
        }
        return cnt;
        
    }

    /*
        only when row(i), col(j) grid[i][j] == 1时候才运行dfs, 直接在grid上操作
    */
    void dfs(vector<vector<char>>& grid, int i, int j) {
        
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == '0')  {
            return;
        }
        
        if (grid[i][j] == '1') {
            // cout << i << " " << j << " " << grid[i][j] << endl;
            grid[i][j] = '0';
            dfs(grid, i-1, j);
            dfs(grid, i+1, j);
            dfs(grid, i, j-1);
            dfs(grid, i, j+1);
        }
    }
};