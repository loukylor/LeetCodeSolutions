class Solution {
    public int[][] solution1(int[][] intervals) {
        List<int[]> workingRanges = new ArrayList<>();
        
        // Loop through all intervals
        for (int i = 0; i < intervals.length; i++) {
            // Loop through workingRanges and adjust the current interval
            // as needed
            for (int k = 0; k < workingRanges.size(); k++) {

                // Check for overlap
                if (checkOverlap(workingRanges.get(k), intervals[i])) {
                    // Adjust interval if overlap
                    intervals[i][0] = Math.min(workingRanges.get(k)[0], intervals[i][0]);
                    intervals[i][1] = Math.max(workingRanges.get(k)[1], intervals[i][1]);
                    
                    // Pop overlapping range
                    workingRanges.remove(k--);
                }
            }
            
            // Add new adjust interval
            workingRanges.add(intervals[i]);
        }
        
        return workingRanges.toArray(new int[workingRanges.size()][2]);
    }
    
    public boolean checkOverlap(int[] lInterval, int[] rInterval) {
        return lInterval[0] <= rInterval[1] && lInterval[1] >= rInterval[0];
    }
  
    public int[][] solution2(int[][] intervals) {
        // Sort array by starting value
        Arrays.sort(intervals, (l, r) -> Integer.compare(l[0], r[0]));
        
        List<int[]> res = new ArrayList<>();
        res.add(intervals[0]);
        
        int currentVal = intervals[0][1];
        for (int i = 1; i < intervals.length; i++) {
            // Check if current val is larger than lower bound of value
            if (currentVal >= intervals[i][0]) {
                // Then it must be overlapping
                currentVal = Math.max(intervals[i][1], currentVal);
                res.get(res.size() - 1)[1] = currentVal;
            } else {
                // It's not overlapping
                res.add(intervals[i]);
                currentVal = intervals[i][1];
            }
        }
        
        return res.toArray(new int[res.size()][2]);
    }
}
