class Solution {
public:
    double myPow(double x, int n) {
        auto quickPow = [](double base, long long exponent) -> double{
            double result = 1.0;
            while (exponent > 0){
                if (exponent & 1){
                    result *= base;
                }
                base *= base;
                exponent >>= 1; 
            }
            return result;
        };
        return n >= 0 ? quickPow(x, n) : 1.0 / quickPow(x, -(long long) n);
    }
};