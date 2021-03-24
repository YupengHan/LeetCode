class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0) return "0";
        bool torf = true;
        if (num < 0) {
            torf = false;
            num = - num;
        }
        
        string ret = "";
        while(num) {
            int a = num / 7, b = num % 7;
            ret = to_string(b) + ret;
            num = a;
        }
        
        return (torf) ? ret : "-"+ret;
        // return ret;
    }
};