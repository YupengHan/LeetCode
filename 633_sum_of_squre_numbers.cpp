#include <cmath>
class Solution {
public:
    bool judgeSquareSum(int c) {
        
        int cc = floor(sqrt(c));
        // cout << cc << endl;
        for (int i = 0; i < cc+1; ++i) {
            if(i*i > ((c)/2 + 1)) {
                // cout << i << " " << ((c)/2 + 1) << endl;
                return false;
            }
            int b = sqrt(c-i*i);
            if ((i*i + b*b) == c) return true;
        }
        return false;
    }
};