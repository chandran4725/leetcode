class Solution {
public:

    bool binary_search(vector<vector<int>>& arr, int x)
    {
        int n = arr.size();
        int m = arr[0].size();


        int low =0,high = n*m-1;

        while(low <= high)
        {
            int mid = (low+high)/2;
            int row = mid / m;
            int col = mid % m;
            if(arr[row][col] == x) return true;
            else if(arr[row][col] > x) high = mid-1;
            else low = mid+1;
        }

        return false;
    }

    bool searchMatrix(vector<vector<int>>& arr, int x) {
        
        return binary_search(arr,x);
       

    }
};