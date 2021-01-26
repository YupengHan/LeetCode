// Backtracking


class Solution {
private:
    vector<int> direction{-1, 0, 1, 0, -1};
    void bt(vector<vector<char>>& board, string& word, bool& findword, int pos, int x, int y) {
        if (x < 0 || y < 0 || x >= board.size() || y >= board[0].size()) {
            return;
        }
        
        if (findword || board[x][y] != word[pos]) {
            return;
        }

        board[x][y] = '0';
        pos++;
        if (pos == word.size()) {
            findword = true;
            return;   
        }
        for (int i = 0; i < 4; ++i) {
            int nx = x + direction[i], ny = y + direction[i+1];
            bt(board, word, findword, pos, nx, ny);
        }
        pos--;
        board[x][y] = word[pos];
        return;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        bool findword = false;
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                bt(board, word, findword, 0, i, j);
            }
        }
        return findword;
    }
};