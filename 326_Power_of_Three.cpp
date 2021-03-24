class Solution {
public:
    bool isPowerOfThree(int n) {
        // cout << log10(n)/log10(3);
        return fmod(log10(n)/log10(3), 1) == 0;
    }
};