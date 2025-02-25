from collections import deque
class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        dq=deque()
        ans=[]
        for i in range(0,len(nums)):
            if len(dq)==0:              #队空时将下标i进队尾
                dq.append(i);
            else:           #队不空时
                while len(dq)>0 and nums[dq[-1]]<nums[i]:
                    dq.pop()                #将队尾小于nums[i]的元素从队尾出队
                dq.append(i)                #将元素下标i进队尾
            if dq[0]<i-k+1:             #将队头过期的元素从队头出队
                dq.popleft()
            if i>=k-1:
                ans.append(nums[dq[0]]) #新队头元素添加到ans中
        return ans
