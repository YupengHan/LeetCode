class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i, csum = 0, j = 0;
        int n = nums.size();
        int ret = INT_MAX;
        csum += nums[j];
        for (int i = 0; i < n; i++) {
            while (j < n-1 && csum < target) {
                j++;
                csum += nums[j];
            }
            if (csum >= target) {
                ret = min(ret, j-i+1);
            }
            else {
                cout << csum << endl;
                return (ret == INT_MAX) ? 0 : ret;
            }
            csum -= nums[i];
            
        }
        return (ret == INT_MAX) ? 0 : ret;
        
    }
};