class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> ans;
        if (nums.size() < 3) return ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size()-2; ++i) {
            if (i != 0 && nums[i] == nums[i-1]) continue;
            vector<vector<int>> result = twosum(nums, i, i+1, nums.size()-1);
            ans.insert(ans.end(), result.begin(), result.end());  
        }
        return ans;
    }

    vector<vector<int>> twosum(vector<int>& nums, int i, int l , int r) {
        int target = -nums[i];
        vector<vector<int>> ans;
        while(l<r) {
            if ((nums[l] + nums[r]) == target) {
                ans.push_back({nums[i], nums[l], nums[r]});
                cout << i << " " << l << " " << r << endl;
                l++;
                r--;
                while(l+1 < nums.size() &&  nums[l+1] == nums[l]) {
                    l++;
                }
                while(r-1 >= 0 && nums[r-1] == nums[r]) {
                    r--;
                }
            }

            else if ((nums[l] + nums[r]) > target) {
                r--;
                while(r-1 >= 0 && nums[r-1] == nums[r]) {
                    r--;
                }
            }
            else if ((nums[l] + nums[r]) < target) {
                l++;
                while(l+1 < nums.size() && nums[l+1] == nums[l]) {
                    l++;
                }
            }

        }
        return ans;
    }
};