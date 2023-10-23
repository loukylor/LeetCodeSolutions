public class Solution 
{
    public bool IsValid(string s) 
    {
        if (s.Length == 1)
            return false;
        
        Stack<char> bracketStack = new();
        foreach (char bracket in s) 
        {
            switch (bracket)
            {
                case ')':
                case ']':
                case '}':
                    if (bracketStack.Count == 0)
                        return false;
                    
                    char openingBracket = bracketStack.Pop();
                    if (!((openingBracket == '(' && bracket == ')')
                       || (openingBracket == '[' && bracket == ']')
                       || (openingBracket == '{' && bracket == '}')))
                        return false;
                    break;
                default:
                    bracketStack.Push(bracket);
                    break;
            }
        }
        
        if (bracketStack.Count > 0)
            return false;
        
        return true;
    }
}