struct mycomp {
	bool operator() (string& a, string& b) {
		if (a.size() != b.size()) {
			return a.size() < b.size();
		}
		else {
			return a < b;
		}
	}
};
class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        mycomp mp;
        sort(nums.begin(), nums.end(), mp);
        int size = nums.size();
        for (int i = 0; i < size; ++i) {
        	cout << nums[i] << endl;
        }
        return nums[size-k];
    }
};