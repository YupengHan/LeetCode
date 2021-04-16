class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        if (nums.size() == 2) {
            if (nums[0] > nums[1]) return 0;
            return 1;       
        }
        int l = 0, r = nums.size()-1;
        while(l+1 < r) {
            int mid = l + (r-l)/2;
            if (nums[mid] > nums[mid+1] && nums[mid] > nums[mid-1]) {
                return mid;
            }
            if (nums[mid] < nums[mid+1]) {
                l = mid;
            }
            else {
                r = mid;
            }
            cout << l << " " << r << endl;
            
        }
        if (nums[l] > nums[r]) return l;
        return r;
    }
};