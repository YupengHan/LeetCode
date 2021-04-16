class Solution {
public:
    vector<int> dire{1, 0, -1, 0, 1};
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.size() == 0) return 0;
        int m = matrix.size(), n = matrix[0].size();

        vector<pair<pair<int,int>, int>> itemVec;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                itemVec.push_back(make_pair(make_pair(i,j), matrix[i][j]));
            }
        }
        sort(itemVec.begin(), itemVec.end(), 
            [](const pair<pair<int, int>, int> &x, const pair<pair<int, int>, int> &y) 
            -> int {return x.second > y.second;});


        vector<vector<int>> lip(m, vector<int>(n,-1));
        int maxDeep = 0;
        for (auto itm : itemVec) {
            pair<int, int> loc = itm.first;
            int curVal = itm.second;
            int curDeep = 1;
            if (lip[loc.first][loc.second] < 0) lip[loc.first][loc.second] = 1;
            for (int i = 0; i < 4; ++i) {
                int ci = dire[i] + loc.first;
                int cj = dire[i+1] + loc.second;
                if (ci >= 0 && ci < m && cj >= 0 && cj < n && 
                    lip[ci][cj] != -1 && curVal < matrix[ci][cj]) {
                    curDeep = curDeep > lip[ci][cj]+1 ? curDeep : lip[ci][cj]+1;
                    // if (loc.first == 2 && loc.second == 0) {
                    //     cout << "--------------------" << endl;
                    //     cout << ci << " " << cj << ": " << lip[ci][cj] << endl;
                    // }

                }
                

            }
            lip[loc.first][loc.second] = curDeep;
            // cout << loc.first << " " << loc.second << ": " << curDeep << endl;
            maxDeep = maxDeep > curDeep ? maxDeep : curDeep;

        }
        return maxDeep;

    }
};