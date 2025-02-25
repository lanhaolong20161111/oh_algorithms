class Solution(object):
    def findLongestChain(self,pairs:List[List[int]])->int:
        n=len(pairs)
        pairs.sort()
        dp=[1]*n
        for i in range(0,n):
            for j in range(i):
                if pairs[i][0]>pairs[j][1]:
                    dp[i]=max(dp[j],dp[j]+1)
        return max(dp)
