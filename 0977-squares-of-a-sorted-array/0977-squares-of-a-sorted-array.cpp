class Solution {
public:
    vector<int> sortedSquares(vector<int>& arr) {
        int n = arr.size();

        vector<int> res;

        int i = 0, j = n - 1;

        while (i <= j) {
            if (abs(arr[i]) > abs(arr[j])) {
                res.push_back(arr[i] * arr[i]);
                i++;
            } else {
                res.push_back(arr[j] * arr[j]);
                j--;
            }
        }

        reverse(res.begin(),res.end());

        return res;
    }
};