public class Solution 
{
    public int[] TopKFrequent(int[] nums, int k) 
    {
        // If k equals the length of nums then all elements are
        // unique
        if (nums.Length == k) 
        {
            return nums;
        }

        // Count how many each unique elements occurs
        Dictionary<int, int> freqDict = new();
        foreach (int num in nums) 
        {
            freqDict[num] = freqDict.GetValueOrDefault(num, 0) + 1;
        }

        // Sort the frequency
        PriorityQueue<int, int> sorted = new();
        foreach (KeyValuePair<int, int> pair in freqDict) 
        {
            sorted.Enqueue(pair.Key, pair.Value);
            if (sorted.Count > k) 
            {
                sorted.Dequeue();
            }
        }

        // Return the top items
        int[] res = new int[k];
        for (int i = 0; i < res.Length; i++)
        {
            res[i] = sorted.Dequeue();
        }
        return res;
    }
}