class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int num = A.size();
        vector<int> endcnt(num, 0);
        if (A.size() < 3) return 0;
        for (int i = 2; i < num; ++i) {
            if (A[i] - A[i-1] == A[i-1] - A[i-2]) {
                endcnt[i] = 1+ endcnt[i-1];
            }
        }
        int cnt = 0;
        for (int i = 0; i < num; ++i) {
            cnt += endcnt[i];
        }
        return cnt;
    }
};