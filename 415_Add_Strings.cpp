class Solution {
public:
    string addStrings(string num1, string num2) {
        string output = "";
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        int onelen = num1.size();
        int twolen = num2.size();
        if (twolen > onelen) {
            swap(num1, num2);
            swap(onelen, twolen);
        }

        int addbit = 0;
        for (int i = 0; i < twolen; ++i) {
            int curbit = (num1[i] - '0') + (num2[i] - '0') + addbit;
            output += to_string(curbit % 10);
            addbit = curbit/10;
        }
        for (int i = twolen; i < onelen; ++i) {
            int curbit = num1[i] - '0' + addbit;
            output += to_string(curbit % 10);
            addbit = curbit/10;
        }
        if (addbit) {
            output += "1";
        }
        reverse(output.begin(), output.end());
        return output;
    }
};