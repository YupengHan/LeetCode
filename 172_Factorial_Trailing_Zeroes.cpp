class Solution {
private:
    int ret;
public:
    void iit(int n) {
        if (n == 0) return;
        else {
            ret += n/5;
            iit(n/5);
        }
    }
    int trailingZeroes(int n) {
        ret = 0;
        iit(n);
        return ret;
    }
};