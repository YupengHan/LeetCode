class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l = 0, r = arr.size()-1;
        cout << l << " " << r << endl;
        while(l+1 < r) {
            int mid = l + (r-l)/2;
            // cout << "mid: " << mid << endl;
            if (arr[mid+1] > arr[mid]) {
                l = mid;
            }
            if (arr[mid+1] < arr[mid]) {
                // cout << "arr[mid+1]: "<<arr[mid+1] << " " << "arr[mid]: " << arr[mid] << endl;
                r = mid;
            }
            // cout << l << " " << r << endl;
        }
        // cout << l << " " << r << endl;
        // cout << "arr[l]: "<<arr[l] << " " << "arr[r]: " << arr[r] << endl;
        if (arr[l] > arr[r]) return l;
        if (arr[l] < arr[r]) return r;
        // return max(arr[l], arr[r]);
        return -1;
    }
};