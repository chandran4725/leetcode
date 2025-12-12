class Solution {
public:
    int helper(vector<int>& arr) {
        int n = arr.size();
        if (n == 1)
            return arr[0];

        int secPrev = arr[0];
        int prev = max(arr[0], arr[1]);

        for (int i = 2; i < n; i++) {
            int pick = arr[i] + secPrev;
            int nonPick = prev;
            secPrev = prev;
            prev = max(pick, nonPick);
        }

        return prev;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];

        vector<int> temp1,temp2;

        for(int i=0;i<n;i++)
        {
            if(i != 0) temp1.push_back(nums[i]);
            if(i != n-1) temp2.push_back(nums[i]);
        }

        return max(helper(temp1),helper(temp2));
    }
};