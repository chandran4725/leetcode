class Solution {
public:
    int findMax(int ind1, int ind2, string& str1, string& str2,
                vector<vector<int>>& dp) {
        if (ind1 >= str1.size() || ind2 >= str2.size())
            return 0;

        if (dp[ind1][ind2] != -1)
            return dp[ind1][ind2];

        if (str1[ind1] == str2[ind2]) {
            return dp[ind1][ind2] =
                       1 + findMax(ind1 + 1, ind2 + 1, str1, str2, dp);
        }

        return dp[ind1][ind2] = max(findMax(ind1 + 1, ind2, str1, str2, dp),
                                    findMax(ind1, ind2 + 1, str1, str2, dp));
    }
    int longestCommonSubsequence(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (str1[i] == str2[j]) {
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
                }
            }
        }

        return dp[0][0];
    }
};