class Solution:
  def tallestBillboard(self,rods:List[int])->int:
    INF=0x3f3f3f3f
    n=len(rods)
    s=sum(rods)
    dp=[-INF]*(s+1)
    dp[0]=0
    for i in range(1,n+1):
      ndp=copy.deepcopy(dp)
      for j in range(0,s+1):
        if j+rods[i-1]<=s:  
          ndp[j+rods[i-1]]=max(dp[j]+rods[i-1],ndp[j+rods[i-1]])
        if rods[i-1]<=j:
          ndp[j-rods[i-1]]=max(dp[j],ndp[j-rods[i-1]])
        else:
          ndp[rods[i-1]-j]=max(ndp[rods[i-1]-j],dp[j]+rods[i-1]-j)
      dp=copy.deepcopy(ndp)
    return dp[0]
