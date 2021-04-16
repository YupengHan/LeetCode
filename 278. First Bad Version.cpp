// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l = 1, r = n;
        while(l + 1 < r) {
            int m = l + (r-l)/2;
            if (isBadVersion(m)) {
                r = m;
            }
            else {
                l = m;
            }
        }

        if (isBadVersion(l)) return l;
        return r;
    }
};