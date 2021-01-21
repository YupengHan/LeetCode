// Newton's Law
// class Solution {
// public:
//     int mySqrt(int x) {
//         long t = x;
//         while(t*t > x) {
//             t = (t+x/t)/2;
//         }
//         return t;
//     }
// };

// Dichotomy 二分法

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0;
        int t = x;
        int l = 1, r = x, mid;
        while (l <= r) {
            mid = l+(r-l)/2;
            // cout << l << " " << r << " " << mid << endl;
            if (x/mid == mid) {
                return mid;   
            }
            else if (mid > (x/mid)) {
                r = mid-1;
            }
            else {
                l = mid+1;
            }
        }
        // return (l*l > x) ? (l-1) : l;
        long dis = long(l)*long(l) - long(x);
        if (dis > 0) return l-1;
        
        return l;
    }
};