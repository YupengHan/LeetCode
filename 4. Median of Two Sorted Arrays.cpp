class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int l1 = nums1.size();
        int l2 = nums2.size();
        int half = (l1 + l2 + 1)/2;
        double m1 = findKth(nums1, nums2, half, 0, 0);
        // cout << "m1: " << m1 << endl;
        if((l1 + l2) % 2 == 1) {
            return m1;
        }
        else {
            double m2 = findKth(nums1, nums2, half+1, 0, 0);
            // cout << "m2: " << m1 << endl;
            return (m1+m2)/2.0;
        } 
    }
    
    int findKth(vector<int>& nums1, vector<int>& nums2, int k, int i1, int i2) {
        // cout << "------ k: " << k << "------    i1: " << i1 << "   i2: " << i2 << endl;
        int n1 = nums1.size()-i1;
        int n2 = nums2.size()-i2;
        if (n1 > n2) return findKth(nums2, nums1, k, i2, i1);
        if (n1 == 0) return nums2[i2+k-1];
        if (k == 1) return nums1[i1]> nums2[i2] ? nums2[i2] : nums1[i1];
        
        
        

        int l1 = n1 > k/2 ? k/2 : n1;
        int l2 = k-l1;
        // cout << "       k: " << k << " l1:" << l1 << "  l2:" << l2 << endl;

        
        if (nums1[i1+l1-1] > nums2[i2+l2-1]) {
            // cout << "num1   " << k-l2 << " " << i1 << " " << i2+l2 << endl;
            return findKth(nums1, nums2, k-l2, i1, i2+l2);
        }
        else {
            // cout << "num2   " << k-l1 << " " << i1+l1 << " " << i2 << endl;
            return findKth(nums1, nums2, k-l1, i1+l1, i2);
        }


    }
};