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