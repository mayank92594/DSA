class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        bool sign = true;

        if((dividend < 0 && divisor > 0) ||
           (dividend > 0 && divisor < 0))
            sign = false;

        long long n = abs((long long)dividend);
        long long d = abs((long long)divisor);

        long long ans = 0;

        while(n >= d) {
            int count = 0;

            while((d << (count + 1)) <= n) {
                count++;
            }

            ans += (1LL << count);
            n -= (d << count);
        }

        if(!sign)
            ans = -ans;

        return ans;
    }
};