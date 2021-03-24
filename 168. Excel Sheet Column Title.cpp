class Solution {
private:
    vector<int> tsbit;
public:
    string convertToTitle(int columnNumber) {
        // if (columnNumber == 1) return "A";
        // columnNumber = columnNumber - 1;
        int a = columnNumber, b = 0;
        while(a) {
            b = (a-1) % 26;
            a = (a-1)/26;
            // cout << b << endl;
            tsbit.push_back(b);
        }
        reverse(tsbit.begin(), tsbit.end());
        map<int, string> bit2str;
        for (int i = 0; i < 26; ++i) {
            bit2str[i] = 'A'+i;
            // cout << bit2str[i] << endl;
        }
        string ret = "";
        for (auto bit : tsbit) {
            cout << bit << endl;
            ret += bit2str[bit];
        }
        return ret;

    }
};