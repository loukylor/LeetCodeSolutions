class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        buy = prices[0]
        sell = prices[0]
        max_profit = 0
        for i in range(1, len(prices)):
            if prices[i] < buy:
                # check if new max
                if sell - buy > max_profit:
                    max_profit = sell - buy
                
                # set low price to new buy
                buy = prices[i]

                # reset sell since we can't sell before we buy
                sell = prices[i]
            elif prices[i] > sell:
                sell = prices[i]
        
        return max(max_profit, sell - buy)