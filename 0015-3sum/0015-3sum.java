class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        int n = nums.length;
        Set<List<Integer>> ans = new HashSet<>();

        for(int i=0;i<n;i++)
        {
            Set<Integer> hash = new HashSet<>();
            for(int j=i+1;j<n;j++)
            {
                int third = -(nums[i] + nums[j]);

                if(hash.contains(third))
                {
                    List<Integer> temp = new ArrayList<>();
                    Collections.addAll(temp,new Integer[]{nums[i],nums[j],third});
                    Collections.sort(temp);
                    ans.add(temp);
                }

                hash.add(nums[j]);
            }
        }

        return new ArrayList<>(ans);
    }
}