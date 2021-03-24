class Solution {
public:
    int minMoves2(vector<int>& nums) {
        auto n = nums.begin()+nums.size()/2;
        nth_element(nums.begin(),n,nums.end());
        int median = *n, mv = 0;
        for(int e:nums) mv+= abs(median - e); 
        return mv;
    }
};



// The code uses C++ built-in algorithms:

// std::nth_element() to partially sort the input in average O(n) time. The algorithm is typically implemented as a variant of quickselect.
// std::accumulate() to accumulate the elements of the input according to the given rule. In our case the rule is to add an absolute difference to the given number. This algorithm also runs in O(n).