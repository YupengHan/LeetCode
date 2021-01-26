/*
    Bubble Sort
*/
// class Solution {
// private: 
//     int myfindK (vector<int>& nums, int k, int vs) { //vs vectot size
//         // cout << k << " " << vs << endl;
//         if (k == 0) {
//             // cout << vs << endl;
//             // cout << nums[5] << " " << nums[4] << endl;
//             return nums[vs];
//         }
//         int cur_pose = 0;
//         for (int i = 0; i < vs; ++i) {
//             if (nums[cur_pose] < nums[i]) {
//                 // cout << cur_pose << ": " << nums[cur_pose] << "   " << i << ": " << nums[i] <<endl;
//                 // swap(nums[cur_pose], nums[i]);
//                 cur_pose = i;
//             }
//         }
//         swap(nums[cur_pose], nums[vs-1]);
//         return myfindK(nums, k-1, vs-1);
//     }
// public:
//     int findKthLargest(vector<int>& nums, int k) {
//         return myfindK(nums, k, nums.size());
//     }
// };

/*
    QuickSort
*/
class Solution {
public:
    int quickSelection(vector<int>& nums, int l, int r) {
        int first = l+1, last = r, key = nums[l];
        while(first < last) {
            while (first< last && nums[first] <= key) {
                first++;
            }
            while (first< last && nums[last] >= key) {
                last--;
            }
            swap(nums[first], nums[last]);
        }
        swap(nums[first], nums[l]);
        return first;
    }
    int findKthLargest(vector<int>& nums, int k) {
        int l = 0, r = nums.size()-1, target = nums.size()-k;
        while(l<r) {
            int mid = quickSelection(nums,l,r);
            cout << mid << " " << nums[mid] << endl;
            if (mid == target) {
                return nums[mid];
            }
            else if (mid > target) {
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        for (int i = 0; i < nums.size(); ++i) {
            cout << nums[i] << " ";
        }
        cout << endl;
        return nums[l];
    }
};




























