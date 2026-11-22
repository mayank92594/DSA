class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for(int b = 0; b < 32; b++) {
            int ones = 0;

            for(int i = 0; i < n; i++) {
                if((nums[i] >> b) & 1) {
                    ones++;
                }
            }

            int zeros = n - ones;
            ans += ones * zeros;
        }

        return ans;
    }
};