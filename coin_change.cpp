/*
    超时算法
*/
// class Solution {
// public:
//     static bool comp(int a, int b) {
//         return a > b;
//     }
//     int coinChange(vector<int>& coins, int amount) {
//         if (amount == 0) return 0; 
//         sort(coins.begin(), coins.end(), comp);
//         for (auto coin:coins) {
//             if (amount == coin) return 1;
//         }

        
//         int cur_num = amount;
//         bool signal = false;
//         for (int i = 0; i < coins.size(); i++) {
//             int comple = amount-coins[i];
//             if (comple < 0) continue;
//             int tmp = coinChange(coins, comple);
//             if (tmp > 0) {
//                 // cout << comple << " " << tmp << endl;
//                 signal = true;
//                 cur_num = min(cur_num, tmp+1);
//             }
//         }
//         if (signal) {
//             return cur_num;
//         }
//         else return -1;
        
//     }
// };


class Solution {
public:
    static bool comp(int a, int b) {
        return a > b;
    }

    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0; 
        sort(coins.begin(), coins.end(), comp);
        for (auto coin:coins) {
            mem_[coin] = 1;
        }
        mem_[0] = 0;
        return ccdp(coins, amount);

    }
private:
    unordered_map <int, int> mem_;
    int ccdp(vector<int>& coins, int amount) {
        // if (amount < 0) {
        //     return -1;
        // }
        
        if (mem_.count(amount)) {
            return mem_(acount);
        }
        
        int tmp = INT_MAX;
        for (int i = 0; i < coins.size(); i++) {
            int res = amount - coins[i];
            if (res < 0) {
                continue;
            }           
            int cnt_res = ccdp(coins, res);
            if (cnt_res >= 0) {
                tmp = min(tmp, cnt_res+1);
            }
        }

        if (tmp == INI_MAX) {
            return -1;
        }
        else {
            mem_[amount] = tmp;
            return tmp;
        }

    }

};