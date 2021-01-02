

// // 超时算法
// class Solution {
// public:
//     int constrainedSubsetSum(vector<int>& nums, int k) {
//         vector<int> dp(nums.size());
//         dp[0] = nums[0];
//         for (int i = 1; i < nums.size(); ++i) {
//             int max_prev = 0;
//             // cout << "loop " << i << endl;
            
//             int st_j = i-k;
//             if (st_j < 0) st_j = 0;
//             for (int j = st_j; j < i; ++j) {
//                 // cout << "fore loop j : " << j << endl;
//                 if (max_prev < dp[j]) max_prev = dp[j];
//                 // cout << "max_prev: " << max_prev << endl;
//             }
//             dp[i] = nums[i] + max_prev;
//             // cout << "dp["<<i<<"]: " << dp[i] << endl;
//         }

//         int ret = dp[0];
//         for (int i = 0; i < nums.size(); ++i) {
//             // cout << dp[i] << endl;
//             if (dp[i] > ret) ret = dp[i];
//         }

//         return ret;

//     }
// };


class Solution {
    
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        vector<int> dp(nums.size());
        dp[0]=nums[0];
        int ans=nums[0];
        deque<int> que{nums[0]};
        for(int i=1;i<nums.size();i++){
            dp[i]=nums[i];
            if(i>k && que[0]==dp[i-k-1]){
                que.pop_front();
            }
            dp[i]=max(dp[i],que[0]+nums[i]);
            while(que.size() && que.back()<dp[i]){
                que.pop_back();
            }
            que.push_back(dp[i]);
            ans=max(ans,dp[i]);
            // cout << "current Deque:" << endl;
            // for (auto it = que.begin(); it != que.end(); ++it) {
            //     cout << ' ' << *it;     
            // }
            // cout <<endl;
            
        }
        return ans;
        //return 0;
    }
};