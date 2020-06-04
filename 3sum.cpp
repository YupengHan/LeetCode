class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ret;
        for (int i = 0; i < n; i++) {
            // cout << nums[i] << ": " <<endl;
            if (nums[i] >0) {
                break;
            }
            if (i!=0 && nums[i] == nums[i-1]) {
                continue;
                
            }
            
            int left = i+1;
            int right = n-1;
            int comple = -nums[i];
            while (left < right) {
                // cout << "left:" << nums[left] <<";right:" <<  nums[right] <<endl;
                // cout << "left:" << left <<";right:" <<  right <<endl;
                if (nums[left] + nums[right] == comple) {
                    ret.insert(ret.end(), {nums[i], nums[left],nums[right]});
                    // cout << "c1" << endl;
                    // continue;
                    left++;
                    while(left < n-1 && nums[left] == nums[left-1]) {
                        left++;
                    }

                    right--;
                    while(right > 0 && nums[right] == nums[right+1]) {
                        right--;
                    }

                    // cout << "left:" << left <<";right:" <<  right <<endl;
                    
                }
                else if (nums[left] + nums[right] > comple) {
                    right--;
                    while(right > 0 && nums[right] == nums[right+1]) {
                        right--;
                    }
                    // cout << "c2" << endl;
                }
                else {
                    left++;
                    while(left < n-1 && nums[left] == nums[left-1]) {
                        left++;
                    }
                    // cout << "c3" << endl;
                }
                
            }

        }
        return ret;        
    }
};