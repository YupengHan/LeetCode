class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        if (a.size() < b.size()) {
            swap(a, b);
        }
        int al = a.size();
        int bl = b.size();

        int addbit = 0;
        string ret = "";
        for (int i = 0; i < bl; ++i) {
            int curbit = (a[i]- '0') + (b[i]- '0') + addbit;
            ret += (curbit%2) + '0';
            addbit = curbit / 2;
        }
        for (int i = bl; i < al; ++i) {
            int curbit = (a[i]- '0') + addbit;
            ret += (curbit%2) + '0';
            addbit = curbit / 2;
        }
        if (addbit) {
            ret += '1';
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};