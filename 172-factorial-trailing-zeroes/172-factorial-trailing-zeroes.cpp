class Solution {
public:
    
    int recurFactorial(int n, int& twos, int& fives) {
        if (n == 0 || n == 1) {
            return 1;
        }
        int ret = recurFactorial(n - 1, twos, fives);
        if (n >= INT_MAX / ret) {
            while (ret % 5 == 0) {
                ++fives;
                ret /= 5;
            }
            while (ret % 2 == 0) {
                ++twos;
                ret /= 2;
            }
            ret = 1;
        }
        ret *= n;
        return ret;
    }
    
    int trailingZeroes(int n) {
        int twos = 0, fives = 0;
        int factorial = recurFactorial(n, twos, fives);
        while (factorial % 5 == 0) {
            ++fives;
            factorial /= 5;
        }
        while (factorial % 2 == 0) {
            ++twos;
            factorial /= 2;
        }
        return min(twos, fives);
    }
};