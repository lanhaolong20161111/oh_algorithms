class Solution:
    def change(self, amount: int, coins: List[int]) -> int:
        n=len(coins)
        dp=[0]*(amount+1)
        dp[0]=1
        for i in range(1,n+1):
            for j in range(1,amount+1):
                if j>=coins[i-1]: #可以选择装入和不装入
                    dp[j]+=dp[j-coins[i-1]]
        return dp[amount]
