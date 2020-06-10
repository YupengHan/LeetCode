class Solution {
public:
    string numberToWords(int num) {
        if (num == 0) return "Zero";
        string ret = "";
        if (num >= 1000000000) {
            int n_ = num/1000000000;
            cout << n_ << endl;
            num -= n_*1000000000;
            ret += threebit(n_) + " Billion ";
            cout << ret << endl;
        }
        if (num >= 1000000) {
            cout << num << endl;
            int n_ = num/1000000;
            num -= n_*1000000;
            ret += threebit(n_) + " Million ";
        }
        if (num >= 1000) {
            cout << num << endl;
            int n_ = num/1000;
            num -= n_*1000;
            ret += threebit(n_) + " Thousand ";
        }
        if (num >= 1) {
            cout << num << endl;
            ret += threebit(num);
        }
        
        

        if (ret[ret.size()-1] == ' ') return ret.substr(0, ret.size()-1);
        return ret;
    }
    string threebit(int num) {
        string myodd[10] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
        string myeven[10] = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        string tenp[10] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        string ret = "";
        int b[3];
        b[0] = num/100;
        num -= (num/100) * 100;
        b[1] = num/10;
        num -= (num/10) * 10;
        b[2] = num;
        // 第一位
        if (b[0] != 0) {
            ret += myodd[b[0]] + " Hundred";
        }
        // 第二位
        if (b[1] != 0) {
            if (b[1] != 1) {
                ret += " " + myeven[b[1]];
            }
            
        }
        
        // 第三位
        if (b[1] == 1) {
            ret += " " + tenp[b[2]];            
        }
        else if (b[2] != 0) {
            ret += " " + myodd[b[2]];
        }

        if (ret[0] == ' ') ret = ret.substr(1, ret.size()-1); 
        return ret;

    }
};