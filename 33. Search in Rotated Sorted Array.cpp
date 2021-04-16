class Solution {
public:
    int search(vector<int>& nums, int target) {
        int pivot;
        int l = 0, r = nums.size() - 1;
        if (nums[l] < nums[r]) {
            pivot = 0;
        }
        else {
            while (l+1 < r) {
                int mid = l + (r-l)/2;
                if (nums[mid] > nums[l]) {
                    l = mid;
                }
                if (nums[mid] < nums[r]) {
                    r = mid;
                }
            }
            if (nums[l] < nums[r]) {
                pivot = l;
            }
            else {
                pivot = r;
            }
        }
        // cout << "pivot: " << pivot << endl;
        int s = 0, e = nums.size()-1;
        while(s + 1 < e) {
            int ns = (s + pivot) % nums.size();
            int ne = (e + pivot) % nums.size();
            // cout << ns << " " << ne << endl;

            int nm = (s+(e-s)/2 + pivot) % nums.size();
            // cout << s+(e-s)/2 << "                          " << nm << endl;

            if (nums[nm] == target) {
                return nm;
            }
            if (nums[nm] > target) {
                e = s+(e-s)/2;
            }
            if (nums[nm] < target) {
                s = s+(e-s)/2;
            }
        }
        
        int ns = (s + pivot) % nums.size();
        int ne = (e + pivot) % nums.size();
        if (nums[ns] == target) return ns;
        if (nums[ne] == target) return ne;
        return -1;
        
    }
};