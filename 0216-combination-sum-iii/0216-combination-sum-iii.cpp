class Solution {
public:

    void findCombinations(int ind,vector<int> &arr,vector<int> &ds,int k,int target,vector<vector<int>> &ans)
    {
        if(target < 0) return;

        if(ds.size() == k && target == 0)
        {
            ans.push_back(ds);
            return;
        }

        if(ind == arr.size()) return;
        
        ds.push_back(arr[ind]);
        findCombinations(ind+1,arr,ds,k,target-arr[ind],ans);
        ds.pop_back();
        

        findCombinations(ind+1,arr,ds,k,target,ans);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> arr = {1,2,3,4,5,6,7,8,9};
        vector<vector<int>> ans;
        vector<int> ds;

        findCombinations(0,arr,ds,k,n,ans);

        return ans;
    }
};