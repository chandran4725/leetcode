class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& arr) {
        
        int size = arr.size();
        int n = size*size;

        long long s = 0;
        long long s2 = 0;

        long long sn = n*(n+1)/2;
        long long s2n = (long long) n*(n+1)*(2*n+1)/6;


        for(int i=0;i<n;i++)
        {
            s += arr[i/size][i%size];
            s2 += (long long)arr[i/size][i%size] * arr[i/size][i%size];
        }

        long long val1 = s - sn;
        long long val2 = s2 - s2n;

        val2 = val2/val1;

        int repeating = (val1+val2)/2;
        int missing = val2 - repeating;

        return {repeating,missing};
    }
};