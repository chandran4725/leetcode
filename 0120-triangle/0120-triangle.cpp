class Solution {
public:
    int findMinPath(int row,int col,vector<vector<int>>& arr,vector<vector<int>>& dp)
    {
        if(row == arr.size() - 1)
        {
            return arr[row][col];
        }

        if(dp[row][col] != -1) return dp[row][col];

        int left = arr[row][col] + findMinPath(row+1,col,arr,dp);

        int right = arr[row][col] + findMinPath(row+1,col+1,arr,dp);

        return dp[row][col] = min(left,right);
    }

    int minimumTotal(vector<vector<int>>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));

        for(int i=0;i<n;i++)
        {
            dp[n-1][i] = arr[n-1][i];
        }

        for(int i = n-2;i>=0;i--)
        {
            for(int j=i;j>=0;j--)
            {
                int left = arr[i][j] + dp[i+1][j];
                int right = arr[i][j] + dp[i+1][j+1];
                dp[i][j] = min(left,right);
            }
        }

        return dp[0][0];

        // return findMinPath(0,0,arr,dp);
    }
};