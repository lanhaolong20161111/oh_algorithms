class Solution:
    def canJump(self, nums: List[int]) -> bool:
        n=len(nums)
        if n==1:return True
        i=0
        while i<n-1:
            end=i+nums[i]
            if end==i:return False     #若nums[i]=0则返回false
            elif end>=n-1:return True   #从位置i可以跳到终点，则返回true
            else:
                maxj=i+1
                for j in range(i+2,end+1):
                    if j+nums[j]>maxj+nums[maxj]:maxj=j
                i=maxj
        return True
