class Solution {
public:
    long long power(long long a, long long b) {
        long long ans = 1;
        long long MOD = 1e9 + 7;

        while (b > 0) {
            if (b % 2 == 1) {
                ans = (ans * a) % MOD;
            }

            a = (a * a) % MOD;
            b = b / 2;
        }

        return ans;
    }

    int countGoodNumbers(long long n) {
        long long MOD = 1e9 + 7;

        long long evenPositions = (n + 1) / 2;
        long long oddPositions = n / 2;

        long long evenWays = power(5, evenPositions);
        long long oddWays = power(4, oddPositions);

        return (evenWays * oddWays) % MOD;
    }
};