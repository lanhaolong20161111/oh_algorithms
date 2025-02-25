class Solution:
    def maxNumberOfApples(self, weight: List[int]) -> int:
        n=len(weight)
        weight.sort()   #递增排序
        ans,r=0,5000
        for i in range(0,n):
            if weight[i]<=r:
                ans+=1
                r-=weight[i]
            else: break
        return ans
