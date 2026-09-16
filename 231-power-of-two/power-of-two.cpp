class Solution {
public:
    bool check(long long power, int k) {
        if (power == k)
            return true;

        if (power > k)
            return false;

        return check(power * 2, k);
    }

    bool isPowerOfTwo(int n) {
        if (n <= 0)
            return false;

        return check(1, n);
    }
};