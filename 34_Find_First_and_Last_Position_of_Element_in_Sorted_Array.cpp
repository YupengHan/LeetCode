class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) {
            vector<int> ret(2, -1);
            return ret;
        }
        if (nums[nums.size()-1] < target) {
            vector<int> ret(2, -1);
            return ret;
        }
        if (nums[0] > target) {
            vector<int> ret(2, -1);
            return ret;
        }
        int l = 0, r = nums.size(), n = nums.size(), mid;
        while(l<=r) {
            mid = l+(r-l)/2;
            if (nums[mid] == target) {
                l = mid;
                break;
            }
            else if (nums[mid] > target) {
                r = mid-1;
            }
            else {
                l = mid+1;
            }
        }
        
        
        if (nums[l] != target) {
            vector<int> ret(2, -1);
            return ret;
        }
        // cout << keep_mid << endl;
        int keep_mid = l,  int_l,  int_r;
        // cout << keep_mid << endl;
        // now keep_mid is one of the number of target
        l = 0;
        r = keep_mid;
        while (l<r) {
            mid = (r+l)/2;
            // cout << l << " " << r << " " << mid << "          " << nums[l] << " " << nums[r] << endl;
            if (nums[mid] < target) {
                l = mid+1;
            }
            else {
                r = mid;
            }
        }
        int_l = r;



        l = keep_mid;
        r = nums.size()-1;
        while (l<r) {
            mid = ceil(float(r+l)/2);
            // cout << l << " " << r << " " << mid << "          " << nums[l] << " " << nums[r] << endl;
            if (nums[mid] > target) {
                r = mid-1;
                // cout << "r: " << r <<endl;
            }
            else {
                l = mid;
            }
        }
        int_r = r;

        vector<int> ret(2,int_l);
        ret[1] = int_r;

        return ret;

    }
};