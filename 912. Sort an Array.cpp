// class Solution {
// public:
//     void swap(int &a, int &b)
//     {
//         int t=a;
//         a = b;
//         b = t;
//     }
//     int partition(vector<int>& nums, int low, int high)
//     {
//         int pivot = nums[high];
//         int partitionIndex = low;
        
//         for(int i = low; i < high; i++)
//         {
//             if(nums[i] <= pivot)
//             {
//                 swap(nums[i], nums[partitionIndex]);
//                 partitionIndex++;
//             }
//         }

//         swap(nums[high], nums[partitionIndex]);
        
//         return partitionIndex;
//     }
//     void quickSort(vector<int>& nums, int low, int high)
//     {
//         if(low<high)
//         {
//             int pivot=partition(nums, low, high);
//             quickSort(nums, low, pivot-1);
//             quickSort(nums, pivot+1, high);
//         }
//     }
//     vector<int> sortArray(vector<int>& nums) 
//     {
//         quickSort(nums, 0, nums.size()-1);
//         return nums;
//     }
// };
class Solution {
public:
    void swap(int &a, int &b) {
        int t=a;
        a = b;
        b = t;
    }
    int partition(vector<int>& nums, int low, int high) {
        int p = nums[high];
        int pIdx = low;
        for (int i = low; i < high; ++i) {
            if (nums[i] <= p) {
                swap(nums[i], nums[pIdx]);
                pIdx++;
            }
        }
        swap(nums[pIdx], nums[high]);
        return pIdx;

    }
    void quickSort(vector<int>& nums, int low, int high) {
        if(low<high) {
            int pivot=partition(nums, low, high);
            quickSort(nums, low, pivot-1);
            quickSort(nums, pivot+1, high);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size()-1);
        return nums;
    }
};