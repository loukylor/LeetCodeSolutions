public class Solution 
{
    public int[] ProductExceptSelf(int[] nums) 
    {
        int[] res = new int[nums.Length];

        int p = 1;
        for (int i = 0; i < nums.Length; i++) 
        {
            res[i] = p;
            p *= nums[i];
        }

        p = 1;
        for (int i = nums.Length - 1; i >= 0; i--) 
        {
            res[i] *= p;
            p *= nums[i];
        }

        return res;
    }
}