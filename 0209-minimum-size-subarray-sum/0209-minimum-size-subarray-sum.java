class Solution {
    public int minSubArrayLen(int target, int[] nums) {
        int n = nums.length;

        int minLen = Integer.MAX_VALUE;

        int left = 0, right = 0;

        int sum = 0;

        while (right < n) {
            sum = sum + nums[right];

            while (sum >= target) {
                int len = right - left + 1;
                minLen = Math.min(minLen, len);
                sum = sum - nums[left];
                left++;
            }

          

            right++;
        }

        return minLen == Integer.MAX_VALUE ? 0 : minLen;
    }
}