// class Solution {
// public:
//     vector<vector<int>> permute(vector<int>& nums) {
//         if (nums.size() == 1) {
//             return {nums};
//         }
//         else {
//             vector<vector<int>> ret;
//             for (int i = 0; i < nums.size(); i++) {
//                 int cur_num = nums[i];

//                 cout << cur_num << endl;
//                 vector<int> tmp_nums(nums.begin(), nums.end());
//                 tmp_nums.erase(nums.begin()+i);

//                 vector<vector<int>> rest_nums = permute(tmp_nums);
//                 for (auto res:rest_nums) {
//                     res.insert(res.begin(), cur_num);
//                     // for (int j = 0; j < res.size(); j++) {
//                     //     cout << res[j] << endl;
//                     // }
//                     for (auto x: res) {
//                         cout << x << endl;
//                     }
                    
//                     ret.insert(ret.end(), res);
//                 }
                
//             }
//             return ret;
//         }
//     }
// };


class Solution {
public:
    
    vector<vector<int>>res;
    
    void checking(vector<int>& nums,int i){
        
        if(i==nums.size()){
        res.push_back(nums);
            return;
        }
        
        
        
        for(int j=i;j<nums.size();j++){
            swap(nums[i],nums[j]);
            checking(nums,i+1);
           swap(nums[i],nums[j]);
        }
        
    }
    

    vector<vector<int>> permute(vector<int>& nums) {
        
        
        checking(nums,0);
        return res;
    }
};