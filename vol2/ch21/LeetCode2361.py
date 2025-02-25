class Solution:
    def minimumCosts(self,regular:List[int],express:List[int],expressCost: int)->List[int]:
        INF=0x3f3f3f3f3f3f3f3f
        n=len(regular)
        dp1=[INF]*(n+1)
        dp2=[INF]*(n+1)
        cost=[0]*n
        dp1[0]=0
        dp2[0]=expressCost
        for i in range(1,n+1):
            dp1[i]=min(dp1[i-1],dp2[i-1])+regular[i-1]
            dp2[i]=min(dp2[i-1],dp1[i-1]+expressCost)+express[i-1]
            cost[i-1]=min(dp1[i],dp2[i])
        return cost
