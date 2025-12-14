class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }

        if (sum % 2 != 0)
            return false;

        vector<vector<bool>> dp(n + 1, vector<bool>(sum / 2 + 1, 0));

        for (int i = 0; i <= n; i++) {
            dp[i][0] = true;
        }

        for (int i = 1; i <= n; i++) {
            for (int target = 1; target <= sum / 2; target++) {
                bool left = dp[i - 1][target];
                bool right = false;
                if (nums[i - 1] <= target) {
                    right = dp[i - 1][target - nums[i - 1]];
                }

                dp[i][target] = left || right;
            }
        }

        return dp[n][sum / 2];
    }
};