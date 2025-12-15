class Solution {
public:
    int findMax(int ind1,int ind2,string &str1,string &str2,vector<vector<int>> &dp)
    {
        if(ind1 >= str1.size() || ind2 >= str2.size()) return 0;

        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];

        if(str1[ind1] == str2[ind2]) 
        {
            return dp[ind1][ind2] = 1 + findMax(ind1+1,ind2+1,str1,str2,dp);
        }

        return dp[ind1][ind2] = max(findMax(ind1+1,ind2,str1,str2,dp),findMax(ind1,ind2+1,str1,str2,dp));
    }
    int longestCommonSubsequence(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();

        vector<vector<int>> dp(n,vector<int>(m,-1));
        return findMax(0,0,str1,str2,dp);
    }
};