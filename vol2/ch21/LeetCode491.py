class Solution:
    def findNumberOfLIS(self, nums: List[int]) -> int:
        n=len(nums)
        maxlen,ans=0,0
        dp=[0]*n
        cnt=[0]*n
        for i in range(0,n):
            dp[i]=1
            cnt[i]=1
            for j in range(0,i):
                if nums[i]>nums[j]:
                    if dp[j]+1>dp[i]:       #找到更大的dp[i]
                        dp[i]=dp[j]+1
                        cnt[i]=cnt[j]   #重置计数
                    elif dp[j]+1==dp[i]:    #找到相同的dp[i]
                        cnt[i]+=cnt[j]
            if dp[i]>maxlen:               #找到更大的maxlen
                maxlen=dp[i]
                ans=cnt[i]              #重置计数
            elif dp[i]==maxlen:         #找到相同的maxlen
                ans+=cnt[i]
        return ans
