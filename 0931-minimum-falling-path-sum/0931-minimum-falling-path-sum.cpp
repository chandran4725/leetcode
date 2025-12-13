class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& arr) {
        int n = arr.size();
        int m = arr[0].size();

        vector<int> prev(m,0);
        vector<int> cur(m,0);

        for(int j=0;j<m;j++)
        {
           prev[j] = arr[n-1][j];
        }

        for(int i=n-2;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                int left = arr[i][j];
                if(j > 0) left += prev[j-1];
                else left += 1e8;

                int right = arr[i][j];
                if(j < m-1) right += prev[j+1];
                else right += 1e8;
                int down = arr[i][j] + prev[j];

                cur[j] = min(left,min(right,down));
            }
            prev = cur;
        }

        int ans = prev[0];

        for(int i=1;i<m;i++)
        {
            ans = min(ans,prev[i]);
        }

        return ans;
    }
};