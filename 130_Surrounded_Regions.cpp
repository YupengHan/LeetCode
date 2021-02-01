// class Solution {
// private:
//     vector<int> dir{-1, 0, 1, 0, -1};
// public:
//     void solve(vector<vector<char>>& board) {
//         if (board.empty()) return;
//         int m = board.size();
//         int n = board[0].size();
//         vector<vector<bool>> visited(m, vector<bool>(n, false));
//         for (int i = 0; i < m; ++i){
//             for (int j = 0; j < n; ++j) {
//                 if (!visited[i][j] && board[i][j] == 'O') {
//                     queue<pair<int, int>> cq;
//                     cq.push(make_pair(i,j));
//                     vector<pair<int, int>> cur_island;
//                     cur_island.push_back(make_pair(i,j));
//                     int min_hor = i;
//                     int max_hor = i;
//                     int min_ver = j;
//                     int max_ver = j;
//                     visited[i][j] = true;
//                     board[i][j] = 'X';
//                     // cout << i << " " << j << endl;
//                     while(!cq.empty()) {
//                         auto [x,y] = cq.front();
//                         // cout << x << " " << y << endl;
                        
//                         min_hor = min(min_hor, x);
//                         max_hor = max(max_hor, x);
//                         min_ver = min(min_ver, y);
//                         max_ver = max(max_ver, y);
//                         cq.pop();
//                         for (int i = 0; i < 4; ++i) {
//                             int nx = x + dir[i], ny = y + dir[i+1];
//                             // cout << "nxy: " << nx << " " << ny << endl;
//                             if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
//                                 // if (!visited[nx][ny] && board[nx][ny] == 'O') {
//                                 // if (board[nx][ny] == 'O') {
//                                     // cout << nx << " " << ny << "|";
//                                     cq.push(make_pair(nx, ny));
//                                     visited[x][y] = true;
//                                     board[x][y] = 'X';
//                                     cur_island.push_back(make_pair(nx, ny));
//                                 }
//                             }
//                         }
//                     }
//                     if (min_hor == 0 || max_hor == m-1 || min_ver == 0 || max_ver == n-1) {
//                         // cout << min_hor << " " << max_hor << " " << min_ver << " " << max_ver << endl;
//                         // cout << "  -------------------------------------------- " << endl;
//                         for (auto [x,y] : cur_island) {
//                             // cout << x << " " << y << " O" << endl;
//                             board[x][y] = 'O';
//                         }
//                     }
//                     else {
//                         // cout << min_hor << " " << max_hor << " " << min_ver << " " << max_ver << endl;
//                         // cout << "  -------------------------------------------- " << endl;
//                         for (auto [x,y] : cur_island) {
//                             // cout << x << " " << y << " X" << endl;
//                             board[x][y] = 'X';
//                         }
//                     }
//                 }
//             }
//         }
//     }
// };







class Solution {
private:
    vector<int> dir{-1, 0, 1, 0, -1};
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty()) return;
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int, int>> outO;
        for (int i = 0; i < n; ++i) {
            visited[0][i] = true;
            if (board[0][i] == 'O') {
                outO.push(make_pair(0,i));
            }
            visited[m-1][i] = true;
            if (board[m-1][i] == 'O') {
                outO.push(make_pair(m-1,i));
            }
        }
        for (int i = 1; i < m-1; ++i) {
            visited[i][0] = true;
            if (board[i][0] == 'O') {
                outO.push(make_pair(i,0));
            }
            visited[i][n-1] = true;
            if (board[i][n-1] == 'O') {
                outO.push(make_pair(i,n-1));
            }
        }
        while(!outO.empty()) {
            auto [x,y] = outO.front();
            outO.pop();
            for (int i = 0; i < 4; ++i) {
                int nx = x + dir[i], ny = y + dir[i+1];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                    if (board[nx][ny] == 'O' && !visited[nx][ny]) {
                        outO.push(make_pair(nx, ny));
                        visited[nx][ny] = true;
                    }
                }
            }
        }



        for (int i = 0; i < m-1; ++i) {
            for (int j = 0; j < n-1; ++j) {
                if (board[i][j] == 'O' && !visited[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};







