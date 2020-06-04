class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if  (nums.size() < 2) return;
        int left = 0;
        bool sig = false;
        for (int i = nums.size()-1; i > 0 ; i--) {
            // cout << i << endl;
            if (nums[i-1] < nums[i]) {
                left = i-1;
                sig = true;
                // cout << left << " " << nums[left] << endl;
                break;
            }
        }

        if (!sig) {
            // cout << "17" << endl;
            rev(nums, 0, nums.size()-1);
            return;
        }


        int right = left+1;
        for (int i = left+1; i < nums.size(); i++) {
            if (nums[i] > nums[left] && nums[i] <= nums[right]) {
                right = i;
            }
        }

        // cout << right << " " << nums[right] << endl;
        swp(nums, left, right);
        rev(nums, left+1, nums.size()-1);
    }
    void rev(vector<int>& nums, int left, int right) {
        while (left < right) {
            swp(nums, left, right);
            left++;
            right--;
        }
    }
    void swp(vector<int>& nums, int left, int right) {
        int tmp = nums[left];
        nums[left] = nums[right];
        nums[right] = tmp;
    }
};