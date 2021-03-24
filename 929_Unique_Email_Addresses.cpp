class Solution {
private:
    unordered_set <string> v_set;
public:
    int numUniqueEmails(vector<string>& emails) {
        for (auto email: emails) {
            size_t at_pos = email.find('@');
            size_t plus_pos = email.find('+');
            string e_n = "";
            if (plus_pos < at_pos) {
                for (int i = 0; i < plus_pos; ++i) {
                    if (email[i] != '.') {
                        e_n += email[i];
                    }
                }
            }
            else {
                for (int i = 0; i < at_pos; ++i) {
                    if (email[i] != '.') {
                        e_n += email[i];
                    }
                }
            }
            for (int i = at_pos; i < email.size(); ++i) {
                e_n += email[i];
            }

            v_set.insert(e_n);
        }
        // for (auto e : v_set) {
        //     cout << e << endl;
        // }
        return v_set.size();
    }
};