class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int all = 1;
        for (int i = 0; i < nums.size(); ++i) {
            all *= nums[i];
        }
        vector<int> ret;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != 0) {
                ret.push_back(all/nums[i]);
            }
            else {
                int cur_num = 1;
                for (int j = 0; j < nums.size(); ++j) {
                    if (j == i) {
                        continue;
                    }
                    cur_num *= nums[j];
                }
                ret.push_back(cur_num);
            }
        }
        return ret;
    }
};