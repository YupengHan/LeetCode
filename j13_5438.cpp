class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if (m*k > n) return -1;
        
        // vector<int>m_nums = bloomDay;
        // sort(m_nums.begin(), m_nums.end());
        // for (auto x:bloomDay) {
        //     x -= m_nums[0];
        // }
        

        // for (int i = 0; i < n; i++) {
        //     if (i != 0) {
        //         int mi = m_nums[i] - m_nums[i-1];
        //         if (mi == 0) continue;
        //     }
            
            
        //     // mi not 0;
        //     if(check_v(bloomDay, m, k, m_nums[i], n)) return m_nums[i];
        // }
        if (!check_v(bloomDay, m, k, 3, 5))
        {
            // cout << "wrong check" << endl;
        }
        
        return -1;
        
    }
    bool check_v(vector<int>& bloomDay, int m, int k, int d, int n) {//check possible for curstate;
        // for (auto x:bloomDay) {
        //     x -= d;
        //     cout << x << " ";
        // }
        // cout << endl;
        
        int cur_m = 0;
        int cnt_k = 0;
        int i = 0;
        while(i < n) {
            cout << bloomDay[i] << endl;
            if ((bloomDay[i]-d) <= 0) {
                cur_m++;
            }
            else {
                cur_m = 0;
            }

            if (cur_m == m) {
                cout << cnt_k << " " << i << endl;
                cnt_k++;
                cur_m = 0;
            }
            i++;
        }
        if (cnt_k >= k) {
            return true;
        }
        
        return false;
        
    }
};