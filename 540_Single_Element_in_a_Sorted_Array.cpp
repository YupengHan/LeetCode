class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 3) {
            if (nums[1] == nums[0]) {
                return nums[2];
            }
            else {
                return nums[0];
            }
        }
        int n = nums.size()/2 + 1;
        int l = 0, r = nums.size()-1;
        if (nums[l] != nums[l+1]) {
            return nums[l];
        }
        if (nums[r] != nums[r-1]) {
            return nums[r];
        }
        while(l<r) {
            int mid = (r-l)/2+l;
            if (mid%2 == 0) {
                if (nums[mid] == nums[mid+1]) {
                    l = mid;
                }
                else if (nums[mid] == nums[mid-1]){
                    r = mid;
                }
                else {
                    return nums[mid];
                }
            }
            else {
                if (nums[mid] == nums[mid-1]) {
                    l = mid;
                }
                else if (nums[mid] == nums[mid+1]) {
                    r = mid;
                }
                else {
                    return nums[mid];
                }
            }
        }
        return nums[l];

    }
};