class Solution {
public:

    bool binary_search(vector<int>& arr,int x)
    {
        int n = arr.size();

        int low =0,high = n-1;

        while(low <= high)
        {
            int mid = (low+high)/2;
            if(arr[mid] == x) return true;
            else if(arr[mid] > x) high = mid-1;
            else low = mid+1;
        }

        return false;
    }

    bool searchMatrix(vector<vector<int>>& arr, int x) {
        int n = arr.size();
        int m = arr[0].size();

        for(int i=0;i<n;i++)
        {
            if(arr[i][0] <= x && x <= arr[i][m-1]) return binary_search(arr[i],x);
        }

        return false;

    }
};