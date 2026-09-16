class Solution {
public:
    bool check(long long power, int k) {
        if (power == k)
            return true;

        if (power > k)
            return false;

        return check(power * 4, k);
    }

    bool isPowerOfFour(int n) {
        if (n <= 0)
            return false;

        return check(1, n);
    }
};