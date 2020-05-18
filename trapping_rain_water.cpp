/*
class Solution {
public:
    //cal sub water
    int subwater(int a, int b, vector<int>& height) {
        int min_tip = height[a]>height[b]? height[b]: height[a];
        int sum = 0;
        for (int i = a+1; i < b; ++i) {
            sum += (height[i]<min_tip) ? (min_tip-height[i]) : 0;
        }
        return sum;
    }
    int trap(vector<int>& height) {
        int len = height.size();
        if (len < 3) return 0;
        // get tips
        vector<int> tips;
        int cur_max = 0;
        int max_id;
        unordered_map <int, int> idx_val;

        for (int i = 0; i < len; i++) {
            if (height[i] >= cur_max) {
                // cout << i << " " << height[i] << endl;
                idx_val[i] = height[i];
                cur_max = height[i];
                tips.push_back(i);
                max_id = i;
            }
        }

        vector<int> back_tips;
        cur_max = 0;
        for (int i = 1; i < len-max_id; i++) {
            if (height[len-i] >= cur_max) {
                // cout << len - i << " " << height[len-i] << endl;
                cur_max = height[len-i];
                back_tips.push_back(i);
            }
        }
        // cout << "                   " << endl;
        for (int i = 1; i <= back_tips.size() ; i++) {
            // cout << back_tips.size()-i << " "<< len - back_tips[back_tips.size()-i] << endl;
            tips.push_back(len - back_tips[back_tips.size()-i]);
        }
      
        //calculate sum
        // cout << "------------------------" << endl;
        int total_sum = 0;
        for (int i = 0; i < tips.size()-1; ++i) {
            // cout << tips[i] << "  " << tips[i+1] << endl;
            total_sum += subwater(tips[i], tips[i+1], height);
            // cout << tips[i] << " " << tips[i+1] << endl;
        }
        return total_sum;
    }
};
*/

class Solution {
public:
    //cal sub water
    int subwater(int a, int b, vector<int>& height) {
        int min_tip = height[a]>height[b]? height[b]: height[a];
        int sum = 0;
        for (int i = a+1; i < b; ++i) {
            sum += (height[i]<min_tip) ? (min_tip-height[i]) : 0;
        }
        return sum;
    }
    int trap(vector<int>& height) {
        int len = height.size();
        if (len < 3) return 0;
        
        // get tips
        vector<int> left_tips, right_tips;
        
        int left_idx, right_idx, left_max, right_max;
        if (height[1] >= height[0]) {
            left_idx = 1;
            left_max = height[1];
            left_tips.insert(left_tips.begin(),left_idx);
        }
        else {
            left_idx = 0;
            left_max = height[0];
            left_tips.insert(left_tips.begin(),left_idx);
        }

        if (height[len-2] >= height[len-1]) {
            right_idx = len-2;
            right_max = height[right_idx];
            right_tips.insert(right_tips.end(),right_idx);
        }
        else {
            right_idx = len-1;
            right_max = height[right_idx];
            right_tips.insert(right_tips.end(),right_idx);
        }
        
        // left_tips.push_back(left_idx);
        // right_tips.insert(right_tips.begin(), right_idx);
        while (right_idx > left_idx) {
            if (left_max <= right_max) { // 从左往右走
                left_idx++;
                if (height[left_idx] >= left_max){
                    left_max = height[left_idx];
                    left_tips.insert(left_tips.end(), left_idx);
                }
            }
            else {
                right_idx--;
                if (height[right_idx] >= right_max) {
                    right_max = height[right_idx];
                    right_tips.insert(right_tips.begin(), right_idx);
                }
            }
        }
        left_tips.insert(left_tips.end(), right_tips.begin(), right_tips.end());
        



        int total_sum = 0;
        for (int i = 0; i < left_tips.size()-1; ++i) {
            // cout << left_tips[i] << "  " << left_tips[i+1] << endl;
            total_sum += subwater(left_tips[i], left_tips[i+1], height);
        }
        return total_sum;

    }
};

/*
上面做法比前一个还慢！！！！　(这是因为leetcode的ＢＵＧ)
insert 比　push_back 快？？？？

// 这是一个好用的答案，
class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) return 0;
        int max_left = 0, max_right = 0, left = 0, right = height.size() - 1;
        int rtn = 0;
        while (left <= right) {
            if (max_left < max_right) {
                if (height[left] > max_left) max_left = height[left];
                else rtn += max_left - height[left];
                ++left;
            } else {
                if (height[right] > max_right) max_right = height[right];
                else rtn += max_right - height[right];
                --right;
            }
        }
        return rtn;
    }
};
*/