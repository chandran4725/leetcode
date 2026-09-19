class Solution {
    public int[] twoSum(int[] arr, int target) {
        int n = arr.length;
        int left = 0;
        int right = n-1;

        while(left < right)
        {
            int sum = arr[left] + arr[right];

            if(sum < target) left++;
            else if(sum > target) right--;
            else return new int[]{(left+1),(right+1)};
        }

        return new int[]{};
    }
}