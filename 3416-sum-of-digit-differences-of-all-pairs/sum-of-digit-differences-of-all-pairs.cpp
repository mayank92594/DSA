class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;

        while (nums[0] > 0) {
            int cnt[10] = {0};

            for (int i = 0; i < n; i++) {
                int digit = nums[i] % 10;
                cnt[digit]++;
                nums[i] /= 10;
            }

            for (int i = 0; i < 10; i++) {
                for (int j = i + 1; j < 10; j++) {
                    ans += 1LL * cnt[i] * cnt[j];
                }
            }
        }

        return ans;
    }
};