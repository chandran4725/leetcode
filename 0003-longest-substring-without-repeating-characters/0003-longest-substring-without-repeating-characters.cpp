class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();

        int r=0,l=0;

        vector<int> hash(256,-1);

        int maxLen = 0;

        while(r < n)
        {
            if(hash[s[r]] != -1)
            {
                if(hash[s[r]] >= l)
                {
                    l = hash[s[r]] + 1;
                }
            }

            int len = r-l+1;

            maxLen = max(maxLen,len);

            hash[s[r]] = r;

            r++;
        }

        return maxLen;
    }
};