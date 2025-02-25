class Solution:
    def combinationSum4(self, nums: List[int], target: int) -> int:
        INF=0x3f3f3f3f3f
        dp=[0]*(target+1)
        dp[0]=1
        for j in range(0,target+1):
            for i in range(1,len(nums)+1):
                if j-nums[i-1]>=0 and dp[j]<INF-dp[j-nums[i-1]]:
                    dp[j]+=dp[j-nums[i-1]];
        return dp[target]
