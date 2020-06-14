class Solution {
private: 
    void solver(vector<vector<char>>& tmp_board, int emp_cnt) {
        if (emp_cnt == 0) return;
        // cout << emp_cnt << endl;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (tmp_board[i][j] == '.') {
                    for (char insert_num = '1'; insert_num < '1'+9; insert_num++) {
                        cout << insert_num << " ";
                        bool insert_num_posib = true;
                        for (int lp = 0; lp < 9; lp++) {
                            
                            if (tmp_board[i][lp] == insert_num || tmp_board[lp][j] == insert_num) {
                                insert_num_posib = false;
                                cout << "insert_num_posib = false ";
                                break;
                            }
                        }
                        if (insert_num_posib) {
                            tmp_board[i][j] = insert_num;
                            cout << i <<" " << j << " " << insert_num << " " << emp_cnt-1 << endl;
                            solver(tmp_board, emp_cnt-1);
                        }
                    }
                    
                }
            }
            
        }
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        int emp_cnt = 0;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') emp_cnt++;
            }
        }
        cout << "-----------" << emp_cnt << "-----------" << endl;
        if (emp_cnt == 0) {
            return;
        }
        else {
            solver(board, emp_cnt);
        }
        


        // while (emp_cnt > 0) {

        // } 
        
        
    }
};