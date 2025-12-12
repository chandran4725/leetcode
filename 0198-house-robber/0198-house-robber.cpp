class Solution {
public:
    int rob(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n,0);
        if(n == 1) return arr[0];
        dp[0] = arr[0];
        dp[1] = max(arr[0],arr[1]);

        for(int i=2;i<n;i++)
        {
            int left = left = arr[i] + dp[i-2];
            

            int right = dp[i-1];

            dp[i] = max(left,right);
        }

        return dp[n-1];
    }
};