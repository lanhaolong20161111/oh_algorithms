import heapq
class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        n=len(nums)
        maxpq=[]             #大根堆
        ans=[]
        for i in range(0,n):
            while len(maxpq)>0 and i-maxpq[0][1]>=k:
                heapq.heappop(maxpq)             #将所有过期的堆顶元素出队
            heapq.heappush(maxpq,[-nums[i],i])
            if i>=k-1:
                ans.append(-maxpq[0][0])
        return ans
