from collections import deque
class Solution:
    def longestSubarray(self, nums: List[int], limit: int) -> int:
        maxdq,mindq=deque(),deque()
        ans,n=0,len(nums)
        low,high=0,0           #窗口的左右边框
        while high<n:
            while len(maxdq)>0 and maxdq[-1]<nums[high]:
                maxdq.pop()
            while  len(mindq)>0 and mindq[-1]>nums[high]:
                mindq.pop()
            mindq.append(nums[high])
            maxdq.append(nums[high])
            while maxdq[0]-mindq[0]>limit:
                if maxdq[0]==nums[low]:
                    maxdq.popleft()
                if mindq[0]==nums[low]: 
                    mindq.popleft()
                low+=1
            ans=max(ans,high-low+1)
            high+=1
        return ans
