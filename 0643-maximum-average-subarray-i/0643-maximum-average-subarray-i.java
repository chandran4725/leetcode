class Solution {
    public double findMaxAverage(int[] nums, int k) {
        int n = nums.length;
        double maxAvg = -Double.MAX_VALUE;

        int left = 0, right = 0;

        double sum = 0;

        while (right < n) {
            sum = sum + nums[right];
            int len = (right - left) + 1;

            if (len > k) {
                sum = sum - nums[left];
                left++;
            }

            len = (right - left) + 1;

            if (len == k) {
                double temp = sum / k;
                maxAvg = Math.max(maxAvg, temp);
            }

            right++;
        }

        return maxAvg;
    }
}