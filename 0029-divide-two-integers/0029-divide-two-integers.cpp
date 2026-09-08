class Solution {
public:
    int divide(int dividend, int divisor) {
        // Overflow case
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        long long a = abs((long long)dividend);
        long long b = abs((long long)divisor);

        long long ans = 0;

        while (a >= b) {
            long long curr = b;
            long long multiple = 1;

            while (a >= (curr << 1)) {
                curr <<= 1;
                multiple <<= 1;
            }

            a -= curr;
            ans += multiple;
        }

        // Apply sign
        if ((dividend < 0) ^ (divisor < 0))
            ans = -ans;

        return (int)ans;
    }
};