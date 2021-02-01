// This is a BFS result



class Solution {
private:
    int islandSize(vector<vector<int>>& grid, int i, int j) {
        grid[i][j] = 2;
        queue<vector<int>> q;
        q.push({i,j});
        int cnt = 1;
        while(!q.empty()) {
            vector<int> c_loc= q.front();
            q.pop();
            int row_i = c_loc[0];
            int col_j = c_loc[1];



            if (row_i-1>=0) {
                if (grid[row_i-1][col_j] == 1) {
                    cnt++;
                    grid[row_i-1][col_j] = 2;
                    q.push({row_i-1, col_j});
                }
            }
            if (row_i+1<grid.size()) {
                if (grid[row_i+1][col_j] == 1) {
                    cnt++;
                    grid[row_i+1][col_j] = 2;
                    q.push({row_i+1, col_j});
                }
            }
            if (col_j-1>=0) {
                if (grid[row_i][col_j-1] == 1) {
                    cnt++;
                    grid[row_i][col_j-1] = 2;
                    q.push({row_i, col_j-1});
                }
            }
            if (col_j+1<grid[0].size()) {
                if (grid[row_i][col_j+1] == 1) {
                    cnt++;
                    grid[row_i][col_j+1] = 2;
                    q.push({row_i, col_j+1});
                }
            }

        }
        return cnt;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        int maxisland = 0;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (grid[i][j] == 1) {
                    int cur_size = islandSize(grid, i, j);
                    maxisland = max(maxisland, cur_size);
                }
            }
        }
        return maxisland;

    }
};



/*
    一般来说，深度优先搜索类型 的题可以分为主函数和辅函数，主函数用于遍历所有的搜索位置，判断是否可以开始搜索，如果 可以即在辅函数进行搜索。辅函数则负责深度优先搜索的递归调用。当然，我们也可以使用栈
(stack)实现深度优先搜索，但因为栈与递归的调用原理相同，而递归相对便于实现，因此刷题时 笔者推荐使用递归式写法，同时也方便进行回溯(见下节)。不过在实际工程上，直接使用栈可 能才是最好的选择，一是因为便于理解，二是更不易出现递归栈满的情况。我们先展示使用栈的 写法。
*/

class Solution {
private:
    vector<int> direction{-1, 0, 1, 0, -1};
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size(), max_area = 0, cur_area, x,y;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (grid[i][j]) {
                    cur_area = 1;
                    grid[i][j]= 0;
                    stack<pair<int, int>> island;
                    island.push({i,j});
                    while(!island.empty()) {
                        auto [r,c] = island.top();
                        island.pop();
                        for (int k = 0; k < 4; ++k) {
                            x = r + direction[k], y = c + direction[k+1];
                            if (x>=0 && x < row && y >=0 && y < col && grid[x][y] == 1) {
                                grid[x][y] = 0;
                                ++cur_area;
                                island.push({x,y});
                            }
                        }
                    }
                    max_area = max(max_area, cur_area);
                }
            }
        }
        return max_area;
    }
};


vector<int> direction{-1, 0, 1, 0, -1}; //这个平行移动的trick很有趣！！！！
// Stack 后进先出！
int maxAreaOfIsland(vector<vector<int>>& grid) {
    int m = grid.size(), n = m? grid[0].size(): 0, local_area, area = 0, x, y;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j]) {
                local_area = 1;
                grid[i][j] = 0;
                stack<pair<int, int>> island;
                island.push({i, j});
                while (!island.empty()) {
                    auto [r, c] = island.top();
                    island.pop();
                    for (int k = 0; k < 4; ++k) {
                        x = r + direction[k], y = c + direction[k+1];
                        if (x >= 0 && x < m &&
                            y >= 0 && y < n && grid[x][y] == 1) {
                            grid[x][y] = 0;
                            ++local_area;
                            island.push({x, y});
                        }
                    }
                }
                area = max(area, local_area);
            }
        }
    }
    return area;
}


 // DFS 递归函数
class Solution {
private:
    vector<int> direction{-1, 0, 1, 0, -1}; //这个平行移动的trick很有趣！！！！
    int dfs(vector<vector<int>>& grid, int r, int c) {
        if (grid[r][c] == 0) return 0;
        grid[r][c] = 0;
        int x,y,area = 1;
        for (int i = 0; i < 4; ++i) {
            x = r+direction[i];
            y = c+direction[i+1];
            if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size()) {
                area += dfs(grid, x, y);
            }
        }
        return area;

    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_area = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j]) {
                    max_area = max(max_area, dfs(grid, i, j));
                }
            }
        }
        return max_area;
    }
};































































