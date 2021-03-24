class Solution {
private:
    unordered_set<int> mset;
    int calbitsq(int n) {
        int ret = 0;
        int a = n, b = 0;
        while(a) {
            b = a%10;
            a = a/10;
            ret += b*b;
        }
        return ret;
    }
public:
    bool isHappy(int n) {
        
        mset.insert(n);
        
        while (n != 1) {
            n = calbitsq(n);
            if (mset.find(n) == mset.end()) {
                mset.insert(n);
                cout << n << endl;
            }
            else {
                return false;
            } 
        }
        return true;
        
    }
};