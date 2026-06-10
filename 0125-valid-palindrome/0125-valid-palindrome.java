class Solution {
    public boolean isPalindrome(String s) {

        int n = s.length();
        StringBuilder str = new StringBuilder();

        for(int i=0;i<n;i++)
        {
            if(Character.isAlphabetic(s.charAt(i)) || (s.charAt(i) >= '0' && s.charAt(i) <= '9')) str.append(Character.toLowerCase(s.charAt(i)));
        }

        String original = str.toString();
        String reversed = str.reverse().toString();

        return original.equals(reversed);
    }
}