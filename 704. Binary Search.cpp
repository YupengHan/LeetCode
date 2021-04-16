class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0) {
            return -1;
        }

        int l =0, r = nums.size()-1;
        while(l+1 < r) {
            int m = l + (r-l)/2;
            if (target == nums[m]) {
                return m;
            }
            if (target > nums[m]) {
                l = m;
            }
            else {
                r = m;
            }

        }
        // cout << l << " " << r <<endl;

        if (target == nums[l]) return l;
        if (target == nums[r]) return r;
        return -1;


    }
};