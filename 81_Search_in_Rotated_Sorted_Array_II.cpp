class Solution {
private:
    // int getidx(int oi, int pivot, int n) {
    //     return (oi >= pivot) ? oi-pivot : n-pivot+oi;
    // }
    int img_real (int img, int pivot, int n) {
        return pivot+img >= n ? pivot+img-n : pivot+img;
    }
public:
    bool search(vector<int>& nums, int target) {
        int pivot = 0;
        int n = nums.size();
        for (int i = 0; i < n-1; ++i) {
            if (nums[i+1] < nums[i]) {
                pivot = i+1;
                break;
            }
        }

        int l = 0, r = nums.size()-1, mid, img;
        while(l<r) {
            mid = (l+r)/2;
            img = img_real(mid, pivot, n);
            if (nums[img] == target) {
                return true;
            }
            else if (nums[img] > target){
                r = mid-1;
            }
            else {
                l = mid+1;
            }
        }

        img = img_real(l, pivot, n);
        if (nums[img] == target) return true;
        return false;


        




    }
};

// how to transfer the i into non-rotate i?
// 2,5,6,0,0,1,2
// 0,1,2,3,4,5,6 size: 7; pivot = 3;
// 4,5,6,0,1,2,3