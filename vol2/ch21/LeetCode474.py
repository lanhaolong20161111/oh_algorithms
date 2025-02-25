class Solution:
    def findMaxForm(self, strs: List[str], m: int, n: int) -> int:
        length=len(strs)
        dp=[[0 for _ in range(n+1)] for _ in range(m+1)]
        for i in range(1,length+1):
            [cnt0,cnt1]=self.Count(strs[i-1])
            for j in range(m,cnt0-1,-1):
                for k in range(n,cnt1-1,-1):
                    dp[j][k]=max(dp[j][k],dp[j-cnt0][k-cnt1]+1)
        return dp[m][n]
    def Count(self,str):
        length=len(str)
        cnt0,cnt1=0,0
        for i in range(0,length):
            if str[i]=='1':cnt1+=1
            else: cnt0+=1
        return [cnt0,cnt1]
