function longestConsecutive(nums: number[]): number {
    const uniqueNums = new Set<number>();

    // Identify unique nums
    for (var num of nums) {
        uniqueNums.add(num);
    }

    // Find which ones are in a row by finding each one in a row, one by one.
    // Despite there being a lot of loops, since each loop delete elements
    // in the set, it won't loop more than N times.
    var max = 0;
    for (var origin of uniqueNums) {
        uniqueNums.delete(origin);
        var currentChain = 1;
        var currentNum = origin;

        // Find those lower than the current
        while (uniqueNums.delete(--currentNum)) {
            currentChain++;
        }

        currentNum = origin;
        // Find those higher than the current
        while (uniqueNums.delete(++currentNum)) {
            currentChain++;
        }

        // Check if the current is the max
        if (currentChain > max) {
            max = currentChain;
        }
    }

    return max;
};