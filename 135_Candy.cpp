// class Solution {
// public:
//     int candy(vector<int>& ratings) {
        

//         int prev_r = ratings[0], prev_c = 1;
//         int num_candy = 1;
//         for (int i = 1; i < ratings.size(); i++) {
//             int cur_candy;
//             int cur_r = ratings[i];
//             if (prev_r < cur_r) {
//                 cur_candy = prev_c+1;
//             }
//             else {
//                 cur_candy = prev_c-1;
//             }
//             if (cur_candy < 1) {
//                 if (prev_r == cur_r) {
//                     cur_candy = 1;
//                 }
//                 if (prev_r > cur_r) {
//                     num_candy += i;
//                     cur_candy = 1;
//                 }
//             }
//             num_candy += cur_candy;
//             prev_c = cur_candy;
//             prev_r = cur_r;
//             // cout << "i: " << i << "; cur_candy: " << cur_candy <<endl;
//         }
        
//         return num_candy;
//     }
// };

class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> candys(ratings.size(), 1);
        for (int i = 1; i < ratings.size(); i++) {
            if (ratings[i] > ratings[i-1] && candys[i] <= candys[i-1]) {
                
                candys[i] = candys[i-1]+1;
                // cout << "candys[i]: " << candys[i] <<endl;
            }
        }
        for (int i = ratings.size()-2; i >= 0; i--) {
            if (ratings[i] > ratings[i+1] && candys[i] <= candys[i+1]) {
                candys[i] = candys[i+1]+1;
            }
        }
        int ret = 0;
        for (auto c : candys) {
            // cout << c << endl;
            ret += c;
        }
        return ret;
        
        
        
    }
};
