// class Solution {
// public:
//     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//         int l1 = nums1.size();
//         int l2 = nums2.size();
//         int half = (l1 + l2 + 1)/2;
//         double m1 = findKth(nums1.begin(), l1, nums2.begin(), l2, half);
//         if((l1 + l2) % 2 == 1){
//             return m1;
//         }
//         else {
//             double m2 = findKth(nums1.begin(), l1, nums2.begin(), l2, half + 1);
//             return (m1+m2)/2.0;
//         }
//     }
    
//     double findKth(vector<int>::const_iterator it1, int n1, vector<int>::const_iterator it2, int n2,int k){
//         if(n1 > n2){
//             return findKth(it2, n2, it1, n1, k);
//         }
//         if(n1 == 0) return *(it2+k-1);
//         if(k == 1) return min(*(it1), *(it2));
            
//         int i = min(n1, k/2);
//         int j = k - i;
//         if(*(it1 + i -1) > *(it2 + j -1)){
//             return findKth(it1, n1, it2+j, n2-j, k-j);
//         }
//         else{
//             return findKth(it1+i, n1-i, it2, n2, k-i);
//         }
            
        
//     }
// };
// [1, 2, 4, 6, 8]
// [2, 3, 4, 7, 8, 9, 11]


class Solution {
private:
    double findKth(vector<int>& nums1, vector<int>& nums2, int K, int n1, int n2, int idx1, int idx2) {
        cout << K << " " << n1 << " " << n2 << " "  << idx1 << " " << idx2 << endl;
        if (n1 > n2) return findKth(nums2, nums1, K, n2, n1, idx2, idx1);
        if (n1 == 0) return nums2[idx2+K - 1];
        if (K == 1) return min(nums1[idx1], nums2[idx2]);
        
        int i = min(K/2, n1);
        int j = K - i;
        if (nums1[idx1+i - 1] > nums2[idx2+j - 1]) {
            return findKth(nums1, nums2, K-j, n1, n2-j, idx1, idx2+j);

        }
        else {
            return findKth(nums1, nums2, K-i, n1-i, n2, idx1+i, idx2);
        }
    }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int l1 = nums1.size();
        int l2 = nums2.size();
        int half = (l1 + l2 + 1)/2;
        double m1 = findKth(nums1, nums2, half, l1, l2, 0, 0);
        cout << "m1: " << m1 << endl;
        if((l1 + l2) % 2 == 1){
            
            return m1;
        }
        else {

            double m2 = findKth(nums1, nums2, half+1, l1, l2, 0, 0);
            cout << "m2: " << m1 << endl;
            return (m1+m2)/2.0;
        }
    }
};































