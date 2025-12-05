class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> res;
        stack<int> st;
        int n =nums.size();
        for(int i=2*n-1;i>=0;i--)
        {
            while(!st.empty() && st.top() <= nums[i %n ])
            {
                st.pop();
            }

            if(i < n)
            {
                int el = st.empty() ? -1 : st.top();
                res.push_back(el);
            }

            st.push(nums[i%n]);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};