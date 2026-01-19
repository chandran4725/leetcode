class Solution {
public:
    void nextPermutation(vector<int>& arr) {
        int n = arr.size();

        int ind = -1;

        for(int i=1;i<n;i++)
        {
            if(arr[i-1] < arr[i])
            {
                ind = i-1;
               
            }
        }

        if(ind == -1)
        {
            reverse(arr.begin(),arr.end());
            return;
        }

        for(int i = n-1;i > ind;i--)
        {
            if(arr[ind] < arr[i])
            {
                swap(arr[i],arr[ind]);
                break;
            }
        }

        reverse(arr.begin()+ind+1,arr.end());

        
    }
};