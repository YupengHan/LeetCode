// class Solution {
// public:
//     bool canPlaceFlowers(vector<int>& flowerbed, int n) {
//         int sizen = flowerbed.size();
//         int max_plant = 0;
//         // int idx = 0;
//         if (sizen == 1) {
//             if (flowerbed[0] == 0) {return (1>=n);}
//             else { return (0>=n);}
//         }
//         if (flowerbed[0] == 0 && flowerbed[1] == 0) {
//             max_plant++;
//             flowerbed[0] = 1;
//         }
//         for (int i = 1; i < sizen-1; ++i) {
//             if (flowerbed[i-1] == 0 && flowerbed[i] == 0 && flowerbed[i+1] == 0) {
//                 max_plant++;
//                 flowerbed[i-1] = 1;
//                 flowerbed[i] = 1;
//                 // flowerbed[i+1] = 1;
//             }
//         }
//         if (flowerbed[sizen-2] == 0 && flowerbed[sizen-1] == 0) {
//             max_plant++;
//             flowerbed[sizen-1] = 1;
//         }
        
//         // cout << max_plant << endl;
//         return (max_plant >= n);
//     }
// };


class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int max_plant = 0;
        for (int i = 0; i < flowerbed.size(); ++i) {
            if (flowerbed[i] == 0) {
                bool avail = true;
                while(avail) {
                    if (i-1 > -1 && flowerbed[i-1] == 1) avail = false;
                    if (i+1 < flowerbed.size() && flowerbed[i+1] == 1) avail = false;
                }
                if (avail) {
                    flowerbed[i] = 1;
                    max_plant++;   
                }
                
            }            
        }
        return (max_plant >= n);
    }
};












