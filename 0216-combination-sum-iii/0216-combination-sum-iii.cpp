class Solution {
public:
    void findCombinations(int ind,int k,int n,vector<int> &ds,vector<vector<int>> &ans)
    {
        

        if(k == 0 && n == 0)
        {
            ans.push_back(ds);
            return;
        }

        if(k <= 0 || n < 0 || ind >= 9) return;

        int el = ind+1;
        ds.push_back(el);
        findCombinations(ind+1,k-1,n-el,ds,ans);
        ds.pop_back();
        findCombinations(ind+1,k,n,ds,ans);
    }
  

    vector<vector<int>> combinationSum3(int k, int n) {
       vector<vector<int>> ans;
       vector<int> ds;

       findCombinations(0,k,n,ds,ans);

       return ans;
    }
};