class Solution {
    public int findPeakElement(int[] nums) {
        int n = nums.length;

        if(n == 0) return -1;

        int maxElement = nums[0];
        int maxIndex = 0;

        for(int i=1;i<n;i++)
        {
            if(nums[i] > maxElement)
            {
                maxElement = nums[i];
                maxIndex = i;
            }
        }

        return maxIndex;
    }
}