// class Solution {
// public:
//     int check_max_side(vector<vector<char>>& matrix, int i, int j, int row, int col) {
//         int cur_dist = 1;
//         for (int dist = 2; dist <= min(row-i, col-j); dist++) {
//             for (int temp_idx = 0; temp_idx < dist; temp_idx++) {
//                 if (matrix[i+dist-1][j+temp_idx] == '0' || matrix[i+temp_idx][j+dist-1] == '0') {
//                     return cur_dist;
//                 }
//             }
//             cur_dist = dist;
//         }
//         return cur_dist;
//     }

//     int maximalSquare(vector<vector<char>>& matrix) {
//         if(matrix.empty()) return 0;
//         int row = matrix.size();
//         int col = matrix[0].size();
        


//         int max_side = 0;

//         // int cnt_row = 0, cnt_col = 0;
//         for (int i = 0; i < row; i++) {
//             if (i+max_side > row) break; 
//             for (int j = 0; j < col; j++) {
//                 if (j+max_side > col) break; 
                
//                 if (matrix[i][j] == '1') {
//                     max_side = max(1, max_side);
//                     int temp_side = check_max_side(matrix, i, j, row, col);
//                     max_side = max(max_side, temp_side);
//                 }
                
//             }
            
//         }
//         return max_side*max_side;
        
//     }

    
// };


class Solution {
public:
    int check_max_side(vector<vector<char>>& matrix, int i, int j, int row, int col) {
        int cur_dist = 1;
        for (int dist = 2; dist <= min(row-i, col-j); dist++) {
            for (int temp_idx = 0; temp_idx < dist; temp_idx++) {
                if (matrix[i+dist-1][j+temp_idx] == '0' || matrix[i+temp_idx][j+dist-1] == '0') {
                    return cur_dist;
                }
            }
            cur_dist = dist;
        }
        return cur_dist;
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;
        int row = matrix.size();
        int col = matrix[0].size();
        cout << row << " " << col << endl;
        


        int max_side = 0;

        int i = 0, j = 0;
        while (i < row && j < col) {
            cout << i << " " << j << " " << matrix[i][j] << endl;
            if (matrix[i][j] == '1') {
                max_side = max(1, max_side);
                int temp_side = check_max_side(matrix, i, j, row, col);
                max_side = max(max_side, temp_side);
                j += temp_side;
                if (j == col) {
                    j = 0;
                    i++;
                }
                
            }
            else { // matrix[i][j] == '0'
                if (j != col -1) {
                    j++;
                }
                else {
                    i++;
                    j = 0;
                }
                
            }
        }
        
        
        return max_side*max_side;
        
    }

    
};

/*
    1 matrix.empty()检查　vector 是否为空！！！！！！
*/