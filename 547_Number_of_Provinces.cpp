// DFS-stack
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<vector<int>> con_list(isConnected.size());
        for (int i = 0; i < isConnected.size(); ++i) {
            for (int j = 0; j < isConnected.size(); ++j) {
                if (isConnected[i][j] && i != j) {
                    con_list[i].push_back(j);
                }
            }
        }

        vector<bool> visited(isConnected.size(), true);

        int cnt = 0;
        for (int i = 0; i < isConnected.size(); ++i) {
            if (visited[i]) {
                cnt++;
                stack<int> openlist;
                openlist.push(i);
                while(!openlist.empty()) {
                    int c = openlist.top();
                    openlist.pop();
                    // cout << c << ": " << endl;
                    for (auto k : con_list[c]) {
                        if (visited[k]) {
                            openlist.push(k);
                            // cout << k << " ";
                            visited[k] = false;
                        }
                    }
                    // cout << endl;

                }

            }
        }
        return cnt;
    }
};


// DFS subfunc

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(), cnt = 0;
        vector<bool> visited(n, false);
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                dfs(isConnected, i, visited);
                ++cnt;    
            }
            
        }
        return cnt;
    }
    void dfs(vector<vector<int>>& isConnected, int i, vector<bool>& visited) {
        visited[i] = true;
        for (int k = 0; k < isConnected.size(); ++k) {
            if (isConnected[i][k] == 1 && !visited[k]) {
                dfs(isConnected, k, visited);
            }
        }
    }
};






























