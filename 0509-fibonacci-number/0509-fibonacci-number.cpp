class Solution {
public:
    int fib(int n) {
        // By Akra Bazi Method
        return 1/(sqrt(5))*(pow(((1+sqrt(5))/2),n) - pow(((1-sqrt(5))/2),n));
    }
};