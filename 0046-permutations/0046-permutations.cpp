class Solution {
public:
    void findPermutations(vector<int> &arr,vector<int> &ds,vector<int> &freq,vector<vector<int>> &ans)
    {
        if(ds.size() == arr.size())
        {
            ans.push_back(ds);
            return;
        }

        for(int i=0;i<arr.size();i++)
        {
            if(!freq[i])
            {
                freq[i] = 1;
                ds.push_back(arr[i]);
                findPermutations(arr,ds,freq,ans);
                ds.pop_back();
                freq[i] = 0;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        vector<int> freq(nums.size(),0);
        findPermutations(nums,ds,freq,ans);
        return ans;
    }
};