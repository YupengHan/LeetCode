class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        int len = s.size();
        vector<string> ret;
        if ( len > 12 || len < 4 ) {
            return ret;
        }
        solution(s, ret, 4, 0);
        
        // int cur_pose[4] = {0,0,0,0};
        // for (int item = 0; item < 4; item++) {
        //     cout << cur_pose[item] << endl;
        //     // for (int  = 0; i < count; i++) {
        //     //     /* code */
        //     // }
            
        // }
        // cout << stoi(s.substr(0,1)) << endl;
        // ret.push_back(s.insert(1, '.'));
        // ret.push_back(s);
        
        return ret;
    }
    void solution(string s, vector<string> &ret, int res_num, int cur_pose) {
        //eg 25525511135
        //   c
        //   2.5525511135
        //     c
        //   25.525511135
        //      c
        //   255.25511135
        //       c
        if (res_num == 1) {
            int new_pose = s.size()-cur_pose;
            // cout << s.substr(cur_pose,new_pose) << endl;
            int last_num = stoi(s.substr(cur_pose,new_pose));
            if (new_pose > 1 && s.substr(cur_pose, 1) == "0") return;
            if (last_num < 256 && last_num >= 0 ) {
                ret.push_back(s);
            }
        }
        else {
            // cout << ":" << endl;
            for (int i = 1; i < 4; i++) {
                string temp_s = s;
                int temp_res_num = res_num-1;
                // cout << temp_s.substr(cur_pose,i) << " " << temp_res_num << " " << temp_s.size()-cur_pose-i;
                if ((i > 1 && temp_s.substr(cur_pose,1) == "0") || stoi(temp_s.substr(cur_pose,i)) > 255 || stoi(temp_s.substr(cur_pose,i)) < 0 || (temp_s.size()-cur_pose-i) > 3*temp_res_num || (temp_s.size()-cur_pose-i) < 1*temp_res_num) {
                    // cout << "Not qualified" << endl;
                    continue;
                }
                temp_s.insert(cur_pose+i, ".");
                // cout << " " << temp_s << " " << temp_res_num << " " << cur_pose+i+1 << endl; 
                solution(temp_s, ret, temp_res_num, cur_pose+i+1);
            }
        }
    }
};

