// class Solution {
// public:
//   unordered_map<int, int> map;
//   int numSquares(int n) {
//     map.insert(make_pair(1,1));
//     int bigSqrt = (int)sqrt(n);
//     int result = n;
//     for (int i = bigSqrt; i > 1; --i) {
//       int i2 = i * i;
//       int eqo = n/i2;

//       if (map.find(n-eqo * i2) == map.end()){
//         map.insert(make_pair(n-eqo * i2, numSquares(n-eqo * i2)));
//       }

//       result = min(result, eqo + map[n-eqo * i2]);
//     }
//     map.insert(make_pair(n, result));
//     return result;
//   }
// };



class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n, 0);
        int maxsub = sqrt(n);
        cout << maxsub << endl;
        for (int i = 0; i < count; ++i) {
            
        }

    }
};








