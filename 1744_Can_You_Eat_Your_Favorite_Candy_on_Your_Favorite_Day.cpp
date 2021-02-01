// class Solution {
// public:
//     vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
//         vector<int> sum_list;
//         int sumcnt = 0;
//         for (auto cc : candiesCount) {
//             sumcnt += cc;
//             sum_list.push_back(sumcnt);
//         }
//         for (auto x: sum_list) {
//             cout << x << " ";
//         }
//         cout << endl;


//         // auto lbx = upper_bound(sum_list.begin(), sum_list.end(), 4);
//         // auto ubx = upper_bound(sum_list.begin(), sum_list.end(), 4);
//         // cout << lbx-sum_list.begin() << " " << ubx-sum_list.begin() << endl;


//         // vector<bool> ret(queries.size(), false);
//         vector<bool> ret;
        
//         for (int i = 0; i < queries.size(); i++) {
//             int favor = queries[i][0];
//             // int yeste = (q[1]-1)*q[2];
//             // auto yubx = upper_bound(sum_list.begin(), sum_list.end(), yeste);
            
//             long long today = (queries[i][1]+1)*queries[i][2];
//             cout << today << " " << sum_list[favor] << endl;
//             if (favor == 0) {
//                 if (today > sum_list[favor]) {
//                     ret.push_back(false);
//                 }
//                 else {
//                     ret.push_back(true);
//                 }
//             }
//             else {
//                 if (today > sum_list[favor] || today < queries[i][1]) {
//                     ret.push_back(false);
//                 }
//                 else {
//                     ret.push_back(true);
//                 }

//             }



//             // int yesterday = (queries[i][1]-1)*queries[i][2];
            


//             // auto tlbx = lower_bound(sum_list.begin(), sum_list.end(), yesterday);
//             // auto tubx = upper_bound(sum_list.begin(), sum_list.end(), today);
//             // cout << today << ":" << tlbx-sum_list.begin() << " | " << tubx-sum_list.begin()<< endl;
//             // int lb = tlbx-sum_list.begin();
//             // int ub = tlbx-sum_list.begin();
//             // cout << today << ":" << lb << " " << ub<< endl;
//             // if (favor >= tlbx-sum_list.begin() && favor <= tubx-sum_list.begin()) {
//             //     ret.push_back(true);
//             // }
//             // else {
//             //     ret.push_back(false);
//             // }
//             // ret[i] = true;
//         }
//         return ret;
//     }
// };


