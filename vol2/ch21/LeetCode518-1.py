class Solution:
    def change(self, amount: int, coins: List[int]) -> int:
        n=len(coins)
        dp=[[0 for _ in range(amount+1)] for _ in range(n+1)]
        for i in range(0,n+1):dp[i][0]=1
        for i in range(1,n+1):
            for j in range(1,amount+1):
                if j<coins[i-1]:    #硬币i-1装不下，不能装入
                    dp[i][j]=dp[i-1][j]
                else:               #可以选择装入和不装入
                    dp[i][j]=dp[i-1][j]+dp[i][j-coins[i-1]]
        return dp[n][amount]
