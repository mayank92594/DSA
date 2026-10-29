class Solution {
public:
    int count = 0;

    void solve(int i, vector<int>& nums, int sum, int target) {
        if (i == nums.size()) {
            if (sum == target)
                count++;

            return;
        }

        solve(i + 1, nums, sum + nums[i], target);
        solve(i + 1, nums, sum - nums[i], target);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        count = 0;
        solve(0, nums, 0, target);
        return count;
    }
};