class Solution {
private:
    int mfm(vector<int>& nums, int l, int r) {
        // cout << l <<" " <<  r << "        " << nums[l] << " " << nums[r] << endl;
        if (r-l <= 1) return min(nums[l], nums[r]);
        
            
        if (nums[l] < nums[r]) {
            return nums[l];
        }
        int mid = (l+r)/2;
        if (nums[mid] > nums[l]) {
            return mfm(nums, mid, r);
        }
        else if (nums[mid] < nums[r]){
            return mfm(nums, l, mid);   
        }
        int ret = nums[r];
        for (int i = l; i <= r; ++i) {
            ret = min(ret, nums[i]);
        }
        return ret;


    }
public:
    int findMin(vector<int>& nums) {
        return mfm(nums, 0, nums.size()-1);
    }
};