// class Solution {
// public:
//     int maximalSquare(vector<vector<char>>& matrix) {
//         int m = matrix.size();
//         int n = matrix[0].size();
//         vector<vector<int>> cnt_mat(m+1, vector<int>(n+1, 0));
//         for (int i = 1; i <= m; ++i) {
//             for (int j = 1; j <= n; ++j) {
//                 if (i == 1 && j == 1) {
//                     cnt_mat[i][j] = matrix[i-1][j-1]-'0';
//                 }
//                 else if (i == 1) {
//                     cnt_mat[i][j] = cnt_mat[i][j-1] + matrix[i-1][j-1]-'0';
//                 }
//                 else if (j == 1) {
//                     cnt_mat[i][j] = cnt_mat[i-1][j] + matrix[i-1][j-1]-'0';
//                 }
//                 else {
//                     cnt_mat[i][j] = cnt_mat[i-1][j] + cnt_mat[i][j-1] - cnt_mat[i-1][j-1] + matrix[i-1][j-1]-'0';
//                 }
//             }
//         }

//         // for (int i = 0; i <= m; ++i) {
//         //     for (int j = 0; j <= n; ++j) {
//         //         cout << "cnt_mat[" << i << "][" << j << "] " << cnt_mat[i][j] << endl;
//         //     }
//         // }
//         int max_side = min(m, n);
//         while(max_side > -1) {
//             for (int i = max_side; i <= m; ++i) {
//                 for (int j = max_side; j <= n; ++j) {
//                     int sq = cnt_mat[i][j] + cnt_mat[i-max_side][j-max_side] - cnt_mat[i][j-max_side] - cnt_mat[i-max_side][j];
//                     if (sq == max_side*max_side) {
//                         return sq;
//                     }
//                 }
//             }
//             max_side--;
//         }
//         return 0;
//     }
// };




class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        int max_side = 0;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (i == 1 || j == 1) {
                    dp[i][j] = matrix[i-1][j-1] - '0';
                    max_side = max(dp[i][j], max_side);
                }
                else {
                    if (matrix[i-1][j-1] == '1') {
                        dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
                        /*
                            这个转换方程没想到！！！！！！不只和top， left有关！
                            还和topleft有关！！！！！！
                        */
                        max_side = max(dp[i][j], max_side);
                    }
                }
            }
        }
        return  max_side*max_side;
    }
};





























