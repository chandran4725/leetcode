class Solution {
public:
    int rob(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n,0);
        if(n == 1) return arr[0];

        int secPrev = arr[0];
        int prev = max(arr[0],arr[1]);

        for(int i=2;i<n;i++)
        {
            int pick = arr[i] + secPrev;
            int nonPick = prev;
            secPrev = prev;
            prev = max(pick,nonPick);
        }

        return prev;
    }
};