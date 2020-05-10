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
        if (height.size() < 3) return 0;
        // get tips
        vector<int> tips;
        if(height[0] > 0 && height[0] > height[1]) tips.push_back(0);
        for (int i = 1; i < height.size()-1; ++i) {
            if (height[i] > height[i-1] && height[i] > height[i+1]) tips.push_back(i);
        }
        if(height[height.size()-1] > 0 && height[height.size()-1] > height[height.size()-2]) tips.push_back(height.size()-1);

        // delete local max
        for (int j = 1; j < tips.size()-1; j++) {
            if (tips[j] < tips[j-1] && tips[j] < tips[j+1]) {
                tips.erase(tips.begin()+j);
                cout << j <<endl;
            }
        }
        
        //calculate sum
        int total_sum = 0;
        for (int i = 0; i < tips.size()-1; ++i) {
            total_sum += subwater(tips[i], tips[i+1], height);
        }
        return total_sum;
    }
};