#include<stdio>
using namespace std;
class Solution {
private:
    vector<int> direction {-1, 0, 1, 0, -1};
    void expandisland(vector<vector<int>>& mmap, vector<vector<int>>& islandA, int x, int y) {
        islandA[x][y] = 1;
        queue<pair<int, int>> q;
        q.push(make_pair(x,y));
        while(!q.empty()) {
            auto [r,c] = q.front();
            cout << "island " << r << " " << c << endl;
            q.pop();
            for (int i = 0; i < 4; ++i) {
                int nx = r + direction[i], ny = c + direction[i+1];
                if (nx >= 0 && nx < mmap.size() && ny >= 0 && ny < mmap[0].size()) {
                    if (mmap[nx][ny] && !islandA[nx][ny]) {
                        q.push(make_pair(nx, ny));
                        islandA[nx][ny] = 1;
                    }
                }
            }
        }
    }
public:
    int shortestBridge(vector<vector<int>>& A) {
        int m = A.size();
        int n = A[0].size();
        // cout << "mn: " << m << " " << n << endl;
        vector<vector<int>> islandA(m, vector<int>(n, 0));
        // cout << "mnislandA: " << islandA.size() << " " << islandA[0].size() << endl;
        bool sig = false;
        for (int i = 0; i < m; ++i) {
            if (sig) break;
            for (int j = 0; j < n; ++j) {
                if (sig) break;
                if (A[i][j]) {
                    expandisland(A, islandA, i, j);
                    sig = true;
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if(islandA[i][j]) {
                    cout << i << " " << j << endl;
                }
            }
        }
        return 0;
    }
};