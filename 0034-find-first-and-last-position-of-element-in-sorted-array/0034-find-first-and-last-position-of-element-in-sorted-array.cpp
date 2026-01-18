class Solution {
public:
    int firstOccurence(vector<int>& arr, int x) {
        int n = arr.size();
        int low = 0, high = n - 1;
        int ans = -1;

            while (low <= high) {
            int mid = (low + high) / 2;

            if (arr[mid] == x) {
                ans = mid;
                high = mid - 1;
            } else if (arr[mid] > x)
                high = mid - 1;
            else
                low = mid + 1;
        }

        return ans;
    }

    int secondOccurence(vector<int>& arr, int x) {
        int n = arr.size();
        int low = 0, high = n - 1;
        int ans = -1;

            while (low <= high) {
            int mid = (low + high) / 2;

            if (arr[mid] == x) {
                ans = mid;
                low = mid + 1;
            } else if (arr[mid] > x)
                high = mid - 1;
            else
                low = mid + 1;
        }

        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int first = firstOccurence(nums,target);

        if(first == -1) return {-1,-1};

        int second = secondOccurence(nums,target);

        return {first,second};
    }
};