// HashMap
// class Solution {
// public:
//     void sortColors(vector<int>& nums) {
//         vector<vector<int>> mMap(3);
//         for (int i = 0; i < nums.size(); ++i) {
//             mMap[nums[i]].push_back(i);
//         }
//         int idx = 0;
//         for (int i = 0; i < 3; i++) {
//             auto l = mMap[i];
//             for (auto item : l) {
//                 nums[idx] = i;
//                 idx++;
//             }
//         }
//         return;
//     }
// };


// Partition in 3 part(Two Pointer)
/*
Old Version: low, how
Now:

< low

>=low <=high

> high

来两次，先把low >=low 分开
再把 >high 分开

*/

// class Solution {
// public:
//     void sortColors(vector<int>& nums) {
//         int l = 0, r = nums.size()-1;
//         while(1) {
//             while(l < r && nums[l] < 1) {
//                 l++;
//             }
//             while(l < r && nums[r] >= 1) {
//                 r--;
//             }
//             if (l >= r) {
//                 break;
//             }
//             swap(nums[l], nums[r]);
//         }

//         r = nums.size()-1;
//         while(1) {
//             while(l < r && nums[l] < 2) {
//                 l++;
//             }
//             while(l < r && nums[r] >= 2) {
//                 r--;
//             }
//             if (l >= r) {
//                 break;
//             }
//             swap(nums[l], nums[r]);
//         }
//         return;
//     }
// };



class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l = 0, r = nums.size() - 1 ;
        int i = 0;
        while(i <= r) {
            if (nums[i]<1) {
                swap(nums[i], nums[l]);
                l++;
                i++;
            }
            else if (nums[i] == 1) {
                i++;
            }
            else {
                swap(nums[i], nums[r]);
                r--;
            }
            cout << i << " " << r << endl;
        }
        return;
    }
};



















































