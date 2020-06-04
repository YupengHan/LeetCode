class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int all = 1;
        for (int i = 0; i < nums.size(); i++) {
            all *= nums[i];
        }
        // cout << all<< endl;
        vector<int> ret;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                int cur = all/nums[i];
                ret.insert(ret.end(), cur);    
            }
            else {
                int t = 1;
                for (int j = 0; j <nums.size(); j++) {
                    if (j == i) continue; 
                    t *=nums[j];
                }
                // cout << i << t<<endl;
                ret.insert(ret.end(), t);
            }
            
        }
        
        return ret;
    }
};