class Solution:
    def profitableSchemes(self,n:int,minProfit:int,group:List[int],profit:List[int])->int:
        mod=1000000007
        m=len(group)
        dp=[[0 for _ in range(minProfit+1)] for _ in range(n+1)]
        dp[0][0]=1
        for i in range(1,m+1):
            for j in range(n,-1,-1):
                for k in range(minProfit,-1,-1):
                    if j>=group[i-1]:
                        dp[j][k]+=dp[j-group[i-1]][max(0,k-profit[i-1])]
                        dp[j][k]%=mod
        ans=0
        for j in range(0,n+1):
            ans=(ans+dp[j][minProfit]) % mod
        return ans
