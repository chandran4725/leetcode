class Solution {
public:
    void findCombinations(int ind, int target, vector<int>& arr,
                          vector<int>& ds, vector<vector<int>>& ans) {
        if (target < 0 || ind > arr.size())
            return;
        if (target == 0) {
            ans.push_back(ds);
            return;
        }

        for (int i = ind; i < arr.size(); i++) {
            if(i > ind && arr[i] == arr[i-1]) continue;
            if(arr[i] > target) return;
            ds.push_back(arr[i]);
            findCombinations(i + 1, target - arr[i], arr, ds, ans);
            ds.pop_back();
        }
        
    }
    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;
        vector<int> ds;

        findCombinations(0, target, arr, ds, ans);

        return ans;
    }
};