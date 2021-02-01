class Solution {
private:
    vector<int> direction{-1,0,1,0,-1};

public:
    int shortestBridge(vector<vector<int>>& A) {
        int m = A.size();
        int n = A[0].size();
        cout << n << endl;
        bool sig = false;
        queue<pair<int, int>> bfsque;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (A[i][j] == 1) {
                    A[i][j] = 2;
                    // cout << i << " " << j << endl;
                    sig = true;
                    queue<pair<int, int>> myque;
                    bfsque.push(make_pair(i,j));
                    myque.push(make_pair(i,j));
                    while(!myque.empty()) {
                        auto [r,c] = myque.front();
                        myque.pop();
                        for (int i = 0; i < 4; ++i) {
                            int x = r+direction[i], y = c+direction[i+1];
                            if (x >= 0 && x < m && y >= 0 && y<n) {
                                if (A[x][y] == 1) {
                                    A[x][y] = 2;
                                    // cout << x << " " << y << endl;
                                    myque.push(make_pair(x,y));
                                    bfsque.push(make_pair(x,y));

                                }
                            }
                        }
                    }
                }
                if(sig) break;
            }
            if(sig) break;
        }

        int level = -1;
        // cout << "A[1][0]: " << A[1][0] << endl;
        // cout << "A[0][1]: " << A[0][1] << endl;
        while(1) {
            int num = bfsque.size();
            level++;
            // cout << "----------------------" << endl;
            // cout << "level"<< level << " " << n << endl;
            // cout << "----------------------" << endl;
            while(num--) {
                auto [x, y] = bfsque.front();
                bfsque.pop();
                // cout << "XY:" << x << " " << y << endl;
                for (int i = 0; i < 4; ++i) {
                    int nx = x + direction[i], ny = y + direction[i+1];
                    // cout << "NXNY:" << nx << " " << ny << endl;
                    // cout << "mn" << m << " " << n << endl;
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                        if (A[nx][ny] == 2) {
                            continue;
                        }
                        else if (A[nx][ny] == 1) {
                            // cout << "A=1:" << nx << " " << ny << endl;
                            return level;
                        }
                        else {
                            A[nx][ny] = 2;
                            bfsque.push(make_pair(nx, ny));
                        }
                        
                        // cout << nx << " " << ny << "| level:" << level << endl;
                        // cout << "topush" << endl;
                    }
                    
                }
            }
        }

        return 0;
    }
};






















