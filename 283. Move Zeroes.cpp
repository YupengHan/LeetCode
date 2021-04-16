class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int nZero = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != 0) {
                nums[nZero] = nums[i];
                nZero++;
            }
        }
        for (int i = nZero; i < nums.size(); ++i) {
            nums[i] = 0;
        }
        // return nums;
    }
};