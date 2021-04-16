class Solution {
public:
    int twoSumLessThanK(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int l = 0, r = nums.size()-1;
        int minDist = INT_MAX;
        while(l < r) {
            // if ((nums[l] + nums[r]) == k) {
            //     cout << l << " " << r << " " << nums[l] << " " << nums[r] << endl;
            //     return 0;
            // }
            // else 
            if ((nums[l] + nums[r]) < k) {
                int curDist = (k - nums[l] - nums[r]);
                if (curDist < minDist) {
                    minDist = curDist;  
                    // cout << nums[l] << " " << nums[r] << " " << curDist << " " << minDist << endl;
                }
                l++;
            }
            else {
                r--;
            }
        }
        cout << minDist << endl;
        if (minDist == INT_MAX) {
            return -1;
        }
        else {
            return k-minDist;
        }
    }
};