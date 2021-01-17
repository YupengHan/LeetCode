// class Solution {
// public:
//     vector<int> twoSum(vector<int>& numbers, int target) {
//         int cnt = numbers.size();
//         vector<int> com_target(4001, -1);
//         for (int i = 0; i < cnt; ++i) {
//             int cct = target-numbers[i] +2000; //+2000 is a encoding thing to keep idx >=0
//             cout << i << " " << cct << endl;
//             if (com_target[cct] != -1) {
//                 com_target[cct] = i;
//             }
//         }

//         for (int i = 0; i < cnt; ++i) {
//             cout << i << " " << numbers[i] << " " << target - numbers[i] +2000 << endl;
//             if (com_target[target - numbers[i] +2000] != -1) {
//                 vector<int>ret(2, i);
//                 cout << ret[0] << endl;
//                 ret[1] = com_target[target - numbers[i] +2000];
//                 return ret;
//             }
//         }
//         return {};


//     }
// };

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int ps = 0;
        int pe = numbers.size()-1;
        while(ps < pe) {
            int csum = numbers[ps] + numbers[pe];
            if (csum == target) {
                return vector<int>{ps+1, pe+1};
            }
            else if (csum < target) {
                ps++;
            }
            else {
                pe--;
            }
        }
        return {};
    }
};