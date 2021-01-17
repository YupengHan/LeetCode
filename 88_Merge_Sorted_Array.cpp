class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int limit_b = -1e9-1;
        vector<int> ret(m+n, limit_b);
        int p1 = 0;
        int p2 = 0;
        int pfinal = 0;
        while(p1 < m && p2 < n) {
            if (nums1[p1] <= nums2[p2]) {
                ret[pfinal] = nums1[p1];
                p1++;
            }
            else {
                ret[pfinal] = nums2[p2];
                p2++;
            }
            pfinal++;
        }

        if (p1 != m) {//p2 full
            while(pfinal != m+n) {
                ret[pfinal] = nums1[p1];
                p1++;
                pfinal++;
            }
        }
        if (p2 != n) {//p2 full
            while(pfinal != m+n) {
                ret[pfinal] = nums2[p2];
                p2++;
                pfinal++;
            }
        }
        nums1 = ret;
    }
};