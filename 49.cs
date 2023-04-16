public class Solution {
    public IList<IList<string>> Solution1(string[] strs) {
        Dictionary<string, IList<string>> res = new();
        StringBuilder builder = new();
        foreach (string str in strs) 
        {
            // Foreach string, create a string containing the
            // number of times each character shows up
            int[] count = new int[26];
            foreach (char chr in str) 
                count[(int)chr - (int)'a']++;

            builder.Clear();
            for (int i = 0; i < count.Length; i++) 
            {
                builder.Append("#");
                builder.Append(count[i].ToString());
            }
            string countString = builder.ToString();

            // If this string is a key in res, then we know
            // it's an anagram of that key, so we add it to
            // the list that is the value of the key.
            if (res.TryGetValue(countString, out IList<string> list)) 
            {
                list.Add(str);
            }
            else
            {
                // If it's not in the res, then add a new list
                // to res at key strDict and add the string
                // to the list
                res[countString] = new List<string> { str };
            }   
        }
        
        return (IList<IList<string>>)res.Values.ToList();        
    }

    public IList<IList<string>> Solution2(string[] strs) {
        Dictionary<string, IList<string>> res = new();
        foreach (string str in strs) 
        {
            // Foreach string, sort it
            char[] chars = str.ToArray();
            Array.Sort(chars);
            string sorted = new(chars);
            
            // If this string is a key in res, then we know
            // it's an anagram of that key, so we add it to
            // the list that is the value of the key.
            if (res.TryGetValue(sorted, out IList<string> list)) 
            {
                list.Add(str);
            }
            else
            {
                // If it's not in the res, then add a new list
                // to res at key strDict and add the string
                // to the list
                res[sorted] = new List<string> { str };
            }   
        }
        
        return (IList<IList<string>>)res.Values.ToList();        
    }
}
