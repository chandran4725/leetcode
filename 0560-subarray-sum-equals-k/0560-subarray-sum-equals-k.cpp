class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        int n = arr.size();

        map<int,int> mp;
        int sum = 0;
        mp[0] = 1;
        int cnt = 0;
        for(int i=0;i<n;i++)
        {
            sum += arr[i];
            int rem = sum - k;
            if(mp.find(rem) != mp.end()) cnt += mp[rem];
            mp[sum] += 1;
        }

        return cnt;
    }
};