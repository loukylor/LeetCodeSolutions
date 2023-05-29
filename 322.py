class Solution:    
    def coinChange(self, coins: List[int], amount: int) -> int:
        # List that corresponds amount to min # of coins
        dp = [0] + [float("inf")] * amount
        
        # Loop through every possible amount
        for curr in range(1, amount + 1):
            min_count = float("inf")
            # Find the minimum number of coins for this amount
            # based off already known coin counts
            for coin in coins:
                if curr - coin < 0:
                    continue
                
                if dp[curr - coin] < min_count:
                    min_count = dp[curr - coin]
            
            dp[curr] = min_count + 1
                
        if dp[amount] == float("inf"):
            return -1
        else:
            return dp[amount]
