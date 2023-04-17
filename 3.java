class Solution {
    public int lengthOfLongestSubstring(String s) {
        if (s.length() == 0) {
            return 0;
        }
        
        // Create map that converts from char to most
        // recent index of the char
        Map<Character, Integer> charIndices = new HashMap<>();
        int begin = 0, end;
        int longest = 1;
        Character current = s.charAt(0);
        charIndices.put(current, 0);
        for (end = 1; end < s.length(); end++) {
            current = s.charAt(end);
            
            // If the end pointer runs across a character
            // in the charIndices map (i.e. a character
            // already in the substring) or at the end of
            // the string, then move the begin pointer to 
            // that charater's most recent occurance plus one
            if (charIndices.containsKey(current) && charIndices.get(current) >= begin) {
                begin = charIndices.get(current) + 1;
            }
            
            if (end - begin + 1 >= longest) {
                longest = end - begin + 1;
            }

            // Store the current end char in the 
            // charIndices map
            charIndices.put(current, end);
        }
        
        return longest;
    }
}
