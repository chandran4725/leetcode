class Solution {
    public int[] productExceptSelf(int[] nums) {
        int n = nums.length;

        int[] ans = new int[n];

        int[] prefix = new int[n];
        int[] suffix = new int[n];

        int pre = 1;
        int suf = 1;

        for(int i=0;i<n;i++)
        {
            pre *= nums[i];
            prefix[i] = pre;

            suf *= nums[n-i-1];
            suffix[n-i-1] = suf;
        }

        ans[0] = suffix[1];
        ans[n-1] = prefix[n-2];

        for(int i=1;i<n-1;i++)
        {
            ans[i] = prefix[i-1] * suffix[i+1];
        }

        return ans;

    }
}