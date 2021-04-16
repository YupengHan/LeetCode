class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, r = numbers.size()-1;
        while(l < r) {
            if ((numbers[l] + numbers[r]) == target) {
                // cout <<numbers[l] << " " << numbers[r] << endl;
                return {l+1, r+1};
            }
            if ((numbers[l] + numbers[r]) > target) {
                r--;
            }
            if ((numbers[l] + numbers[r]) < target) {
                l++;
            }

        }
        return {};
    }
};