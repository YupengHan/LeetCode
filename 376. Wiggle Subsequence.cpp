class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        vector<pair<int,int>> bottdp(n, {0,0});
        vector<pair<int,int>> peakdp(n, {0,0});
        bottdp[0] = make_pair(1, nums[0]);
        peakdp[0] = make_pair(1, nums[0]);
        for (int i = 1; i < n; ++i) {
            //bottdp
            if (nums[i] < peakdp[i-1].second) {
                bottdp[i] = make_pair(peakdp[i-1].first+1, nums[i]);
            }
            else {
                bottdp[i] = bottdp[i-1];
            }
            //peakdp
            if (nums[i] > bottdp[i-1].second) {
                peakdp[i] = make_pair(bottdp[i-1].first+1, nums[i]);
            }
            else {
                peakdp[i] = peakdp[i-1];
            }
        }
        return max(bottdp[n-1].first, peakdp[n-1].first);
    }
};