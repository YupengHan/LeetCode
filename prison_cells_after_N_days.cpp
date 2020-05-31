class Solution {
public:
    template<typename T>
    vector<T> slice(vector<T> const &v, int m) {
        auto first = v.begin() + m;
        auto last = v.end();

        vector<T> ret(first, last);
        return ret;
    }
    
    void print_v_i(vector<int> &v) {
        for (int i = 0; i < v.size(); i++) {
            //cout << v[i] << " ";
        }
        //cout << endl;
    }


    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        vector<int> temp = cells;
        if (N == 0) return temp;
        vector<vector<int>> records;
        vector<vector<int>> loops;
        int res = N;

        while (res != 0) {
            res--;
            // cout << res << ": "<< endl;
            print_v_i(temp);
            vector<int> new_temp = temp;
            for (int i = 1; i < 7; i++) {
                new_temp[i] = (temp[i-1] != temp[i+1])?0:1;
            }
            new_temp[0] = 0, new_temp[7] = 0;
            print_v_i(new_temp);
            temp = new_temp;
            


            for (int i = 0; i < records.size(); i++) {
                int signal = 1;
                for (int j = 0; j < 8; j++) {
                    if (records[i][j] != temp[j]) {
                        signal = 0;
                        break;
                    }
                }
                if (signal == 1) {

                    loops = slice(records, i);
                    break;
                }    
            }
            if (!loops.empty()) {
                break;
            }

            records.push_back(temp);
            
        }
        if (loops.empty()) {
            return temp;
        }
        else {
            // cout << "printing loops:" << endl;
            // cout << "- - - - - - - - - - - -- - - -" << endl;
            for (int i = 0; i < loops.size(); i++) {
                print_v_i(loops[i]);
            }
            // cout << loops.size() << endl;
            // cout << res << endl;
            // cout << res%(loops.size()) << endl;
        }
        int idx = res%(loops.size());
        return loops[idx];
        

        return temp;
    }

    
};