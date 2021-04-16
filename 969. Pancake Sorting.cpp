class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> ret;
        int l = 0;
        int r = arr.size() -1;
        
        int curMaxItem = arr.size();
        while(curMaxItem > 1) {
            // cout <<curMaxItem << " " << r << endl;
            vector<int>::iterator curMaxLoc = find(arr.begin(), arr.begin()+r+1, curMaxItem);
            // cout << "curMaxLoc: " << curMaxLoc << endl;
            int curMove = curMaxLoc-arr.begin() + 1;
            ret.push_back(curMove);
            // for (int i = 0; i < arr.size(); ++i) {
            //     cout << arr[i] << " ";
            // }
            // cout << endl;
            // cout << "current curMove: " << curMove << endl;
            move(arr, curMove);
            // for (int i = 0; i < arr.size(); ++i) {
            //     cout << arr[i] << " ";
            // }
            // cout << endl;
            // cout << "--------------" << endl;
            // cout << curMove << " ";
            curMove = r+1;
            
            ret.push_back(curMove);
            move(arr, curMove);
            // cout << curMove << " ";
            // cout << endl;
            r--;
            curMaxItem--;
            // for (int i = 0; i < arr.size(); ++i) {
            //     cout << arr[i] << " ";
            // }
            // cout << endl;
            // cout << "--------------" << endl;
            


        }

        return ret;
    }
    void move(vector<int>& arr, int k) {
        int l = 0, r = k-1;
        while(l < r) {
            swap(arr[l], arr[r]);
            l++, r--;
        }
        return;
    }
};