/*
    My first idea is backtracking search
    超时
*/
// class Solution {
// private:
//     bool canpar;
//     void bt(vector<int>& nums, int target, int start_idx, vector<bool>& visited) {
//         // cout << target << " " << start_idx << endl;
//         if (start_idx == nums.size()) {
//             // cout << start_idx << " " << nums.size() << endl;
//             return;   
//         }
//         if (target == nums[start_idx] && !visited[start_idx]) {
//             visited[start_idx] = true;
//             canpar = true;
//             return;
//         }
//         if (target < nums[start_idx]) return;
//         visited[start_idx] = true;
//         bt(nums, target - nums[start_idx], start_idx+1, visited);
//         visited[start_idx] = false;
//         bt(nums, target, start_idx+1, visited);
//         return;
//     }
// public:
//     bool canPartition(vector<int>& nums) {
//         int cnt = 0;
//         for (int i = 0; i < nums.size(); ++i) {
//             cnt += nums[i];
//         }
//         if (cnt % 2 == 1) {
//             cout << cnt << endl;
//             return false;
//         }
//         sort(nums.begin(), nums.end(), [](int a, int b) {return a < b;});
//         vector<bool> visited(nums.size(), false);
//         canpar = false;
//         bt(nums, cnt/2, 0, visited);
//         return canpar;
//     }
// };




/*
    相比之下还是dp记忆力强很多
    注意bt算法时间！
*/

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int cnt = 0;
        for (int i = 0; i < nums.size(); ++i) {
            cnt += nums[i];
        }
        if (cnt % 2 == 1) return false;
        int target = cnt/2;
        vector<vector<bool>> dp(nums.size()+1, vector<bool>(target+1, false));

        for (int i = 0; i < nums.size()+1; ++i) {
            dp[i][0] = true;
        }


        for (int i = 1; i <= nums.size(); ++i) {
            for (int j = 1; j <= target; ++j) {
                if (nums[i-1] <= j) {
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];
                }
                else {
                    dp[i][j] = dp[i-1][j];
                }
                // cout << dp[i][j] << endl;
                
            }
            // if (dp[i][target]) {
            //     cout << i << " " << target << endl;
            //     return true;   
            // }
        }
        // cout << " here ";
        for (int i = 0; i <= nums.size(); ++i) {
            for (int j = 0; j <= target; ++j) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }

        return false;

    }
};








































