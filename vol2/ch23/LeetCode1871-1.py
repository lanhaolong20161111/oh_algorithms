class Solution:
    def canReach(self, s:str,minJump:int,maxJump: int)->bool:
        n=len(s)
        if s[n-1]=='1':return False
        dp=[0 for _ in range(n)]
        presum=[0 for _ in range(n+1)]
        presum[0],presum[1]=0,1
        dp[0]=1
        for i in range(1,n):
            if s[i]=='0':
                l,r=max(0,i-maxJump),i-minJump
                if r>=0 and l<=r and presum[r+1]-presum[l]>0:
                    dp[i]=1
            presum[i+1]=presum[i]+dp[i]
        return True if dp[n-1]==1 else False
