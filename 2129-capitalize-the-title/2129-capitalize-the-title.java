class Solution {
    public String capitalizeTitle(String title) {
        int n = title.length();

        boolean isFirstChar = true;

        StringBuilder result = new StringBuilder();
        StringBuilder part = new StringBuilder();

        for(int i=0;i<n;i++)
        {
            

            if(isFirstChar) 
            {
                part.append(Character.toUpperCase(title.charAt(i)));
                isFirstChar = false;
            }
            

            else if(title.charAt(i) == ' ')
            {
                if(part.length() <= 2) result.append(part.toString().toLowerCase()).append(' ');
                else result.append(part).append(' ');
                isFirstChar = true;
                part.setLength(0);
            }

            else part.append(Character.toLowerCase(title.charAt(i)));


        }

        if(part.length() <= 2) result.append(part.toString().toLowerCase());
        else result.append(part);

        return result.toString();
    }
}