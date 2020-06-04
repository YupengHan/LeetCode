// class Solution {
// public:
//     int subarraySum(vector<int>& nums, int k) {
//         int len = nums.size();
//         int ret = 0;
//         for (int i = 0; i < len; i++) {
//             int cur_sum = 0;
//             for (int j = i; j < len; j++) {
//                 cur_sum += nums[j];
//                 if (cur_sum == k) {
//                     ret++;
//                 }
                
//             }
            
//         }
//         return ret;
        
//     }
// };

/*
    方法:prefix sum!
    Key ideas, keep the count of prefix sum!
*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> um; // first: prefix_sum, second: how many times
        um[0] = 1;
        int sum = 0;
        int ret = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (um.count(sum-k)) {
                ret += um[sum-k];
                cout << i << " " << ret << endl;
            }
            
            if (um.count(sum)) {
                um[sum]++;
            }
            else {
                um[sum] = 1;
            }

        }
        return ret;
        
    }
};