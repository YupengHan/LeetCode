class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int b_cnt = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i-1] > nums[i]) {
                if (i == 1) {
                    b_cnt--;
                    nums[i-1] = - 100000;
                }
                else {
                    
                }
            }
        }
        return true;
    }
};