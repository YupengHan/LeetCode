// class Solution {
// public:
//     int minAbsDifference(vector<int>& nums, int goal) {
//         vector<int> sums(nums.size()+1, 0);
//         for (int i = 0; i < nums.size(); ++i) {
//             sums[i+1] = nums[i] + sums[i];
//         }
//         int minAbs = abs(goal);
//         for (int i = 0; i < nums.size(); ++i) {
//             for (int j = i+1; j <= nums.size(); ++j) {
//                 int curSum = sums[j] - sums[i];
//                 if (j == 4 && i == 1) cout << curSum << endl;
//                 if (abs(curSum-goal) < minAbs) {
//                     minAbs = abs(curSum-goal);
//                     cout << i << " " << j << " " << curSum << endl;   
//                 }
//             }
//         }
//         return minAbs;
//     }
// };