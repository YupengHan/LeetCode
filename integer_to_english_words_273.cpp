class Solution {
public:
    string numberToWords(int num) {
        if (num == 0) return "Zero";
        ret = ""
        if (num >= 1000000000) {
            int n_ = num/1000000000;
            num -= (num/1000000000)*1000000000;
            ret += threebit(n_) + " Billion ";
        }
        if (num >= 1000000) {
            int n_ = num/1000000;
            num -= (num/1000000000)*1000000000;
            ret += threebit(n_) + " Billion ";
        }
        

        
        return threebit(num);
    }
    string threebit(int num) {
        string myodd[10] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
        string myeven[10] = {"", "Ten", "Twenty", "Thirty", "Fourty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninty"};
        string tenp[10] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Ninteen"};
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