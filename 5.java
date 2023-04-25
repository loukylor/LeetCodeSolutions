class Solution {
    public String longestPalindrome(String s) {
        // Loop through centers
        int longestBegin = 0;
        int longestEnd = 0;
        for (int i = 0; i < s.length(); i++) {
            // Loop while char before and char after
            // are equal
            int begin = i;
            int end = i;
            while (begin >= 0 && end < s.length()
                   && s.charAt(begin) == s.charAt(end)) {
                begin--;
                end++;
            }
            
            // Revert back once since the condition is no
            // longer back
            begin++;
            end--;
            
            if (end - begin  > longestEnd - longestBegin) {
                longestBegin = begin;
                longestEnd = end;
            }

            
            // Loop while char before and char after
            // are equal
            begin = i;
            end = i + 1;
            while (begin >= 0 && end < s.length()
                   && s.charAt(begin) == s.charAt(end)) {
                begin--;
                end++;
            }
            
            // Revert back once since the condition is no
            // longer back
            begin++;
            end--;
            
            if (end - begin  > longestEnd - longestBegin) {
                longestBegin = begin;
                longestEnd = end;
            }

        }
        
        return s.substring(longestBegin, longestEnd + 1);
    }
}
