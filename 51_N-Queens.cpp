class Solution {
private:
    
    void bt(vector<vector<string>>& ret, int n, vector<bool>& column, vector<bool>& ldiag, vector<bool>& rdiag,
        int pos, vector<string>& curstate) {
        
        if (pos == n) {
            ret.push_back(curstate);
            return;
        }
        for (int i = 0; i < n; ++i) {
            // cout << !column[i] << endl;
            // cout << !rdiag[i+pos] << endl;
            // cout << ldiag[i-pos+n-1] << endl;
            
            if (!column[i] && !rdiag[i+pos] && !ldiag[i-pos+n-1]) {
                // cout << pos << " " << i << " " << endl;
                curstate[pos][i] = 'Q';
                column[i] = rdiag[i+pos] = ldiag[i-pos+n-1] = true;
                bt(ret, n, column, ldiag, rdiag, pos+1, curstate);
                column[i] = rdiag[i+pos] = ldiag[i-pos+n-1] = false;
                curstate[pos][i] = '.';
                
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ret;
        vector<bool> column(n, false);
        vector<bool> ldiag(2*n-1, false);
        vector<bool> rdiag(2*n-1, false);
        vector<string> curstate (n, string(n,'.'));
        int pos = 0;
        bool complete = false;
        bt(ret, n, column, ldiag, rdiag, 0, curstate);
        return ret;
    }
};

