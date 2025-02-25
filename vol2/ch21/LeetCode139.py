class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        n=len(s)
        hset=set()
        for e in wordDict:hset.add(e)
        dp=[False]*(n+1)
        dp[0]=True
        for i in range(1,n+1):
            for j in range(0,i):
                w=s[j:i]
                if dp[j] and w in hset:
                    dp[i]=True
                    break
        return dp[n]
