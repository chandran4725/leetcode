class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();

        int i = 0, j = (i+1);

        int cnt = 1;

        int ind = 0;

        nums[ind++] = nums[i];

        while(i < n && j < n)
        {
            if(nums[i] == nums[j]) j++;
            else if(nums[i] != nums[j]){
                nums[ind++] = nums[j];
                i = j;
                j = (i+1);
                cnt++;
            }
        }
        return cnt;
    }
};