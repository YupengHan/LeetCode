class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int l = 0, r = nums.size()-1;
        int target = nums.size()-k;
        while(l<r) {
            int mid = partition(nums, l, r);
            // cout << mid << endl;
            // for (auto n:nums) {
            //     cout << n << " ";
            // }
            // cout << endl;
            if (mid == target) {
                return nums[mid];
            }
            else if (mid > target) {
                r = mid-1;
            }
            else {//mid < target
                l = mid + 1;
            }
        }
        return nums[l];
    }
    int partition(vector<int>& nums, int l, int r) {
        int keepIdx = r;
        int pivot = nums[r];
        // cout << r << endl;
        // cout << "pivot " << pivot << "pivot Idx: " << r << endl; 
        r--;
        while(1) {
            while(l < r && nums[l] < pivot) {
                l++;
            }
            while(l < r && nums[r] >= pivot) {
                r--;
            }
            if (l>=r) {
                break;
            }
            // swap(nums[l], nums[r]);
            // cout << "swap " << l << " " << r << endl;
            int tmp = nums[l];
            nums[l] = nums[r];
            nums[r] = tmp;
        }
        
        if (nums[r] < pivot) {
            int tmp = nums[r+1];
            nums[r+1] = nums[keepIdx];
            nums[keepIdx] = tmp;
            return r+1;    
        }
        else {
            int tmp = nums[r];
            nums[r] = nums[keepIdx];
            nums[keepIdx] = tmp;
            return r;
        }
        return -1;
    }

};