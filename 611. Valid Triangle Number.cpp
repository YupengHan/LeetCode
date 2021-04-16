
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        for (int rr = nums.size()-1; rr >= 2; rr--) {
            int l = 0, r = rr-1;
            while(l < r) {
                if (nums[l] + nums[r] > nums[rr]) {
                    ans += r-l;
                    r--;
                }
                else {
                    l++;
                }
            }

        }
        return ans;
    }
};








