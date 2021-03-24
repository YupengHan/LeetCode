class Solution {
private:
    vector<int> original;
public:
    Solution(vector<int>& nums) {
        original = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return original;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        if (original.empty()) return {};
        vector<int> shuffled(original);
        int n = original.size();
        for (int i = 0; i < n-1; ++i) {
            int pos = rand() % (n-i);
            swap(shuffled[i], shuffled[ i + pos]);
        }
        return shuffled;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */