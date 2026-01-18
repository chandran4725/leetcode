class Solution {
public:
    int findRow(vector<vector<int>>& arr,int col)
    {
        int n = arr.size();
        int maxi = -1;
        int index = -1;
        for(int i=0;i<n;i++)
        {
            if(arr[i][col] > maxi)
            {
                maxi = arr[i][col];
                index = i;
            }
        }
        return index;
    }
    vector<int> findPeakGrid(vector<vector<int>>& arr) {
        int n = arr.size();
        int m = arr[0].size();

        int low = 0,high = m-1;

        while(low <= high)
        {
            int mid = (low + high)/2;

            int row = findRow(arr,mid);

            int left = mid-1 >= 0 ? arr[row][mid-1] : -1;
            int right = mid+1 < m ? arr[row][mid+1] : -1;

            if(arr[row][mid] > left && arr[row][mid] > right) return {row,mid};
            else if(arr[row][mid] < left) high = mid-1;
            else low = mid+1;
        }
        return {-1,-1};
    }
};