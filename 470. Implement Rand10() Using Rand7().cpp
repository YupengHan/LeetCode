// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        int r = 0, c = 0, num = 0;
        do{
            r = rand7();
            c = rand7();
            num = c+(r-1)*7;
        }while(num > 40);
        return 1 + num % 10;
    }
};