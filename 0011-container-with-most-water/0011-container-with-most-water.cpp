class Solution {
public:
    int maxArea(vector<int>& arr) {
        int n = arr.size();

        int i = 0, j = n-1;

        int res = 0;

        while(i <= j)
        {
            int width = (j - i);

            int mini = min(arr[i],arr[j]);

            res = max(res,(width*mini));

            if(arr[i] > arr[j]) j--;
            else i++;
        }

        return res;
    }
};