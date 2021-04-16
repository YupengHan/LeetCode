class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int idx = 0;
        // cout << nums.size() << endl;
        int n = nums.size();
        for (int i = 0; i < n-1; ++i) {
            // cout << "i: " << i << endl;
            
            if (nums[idx] == nums[idx+1]) {
                nums.erase(nums.begin()+idx);
                // cout << idx << endl;
            }
            else {
                // cout << idx << " " << nums[idx] << endl;
                idx++;
            }
        }

        return nums.size();
    }
};