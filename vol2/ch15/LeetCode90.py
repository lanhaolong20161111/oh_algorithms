class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        n=len(nums)
        nums.sort()
        ans=set()
        for V in range(0,2<<(n-1)):
            ans.add(tuple(self.subs(nums,V)))
        ret=[]
        for s in ans:ret.append(s)
        return ret

    def subs(self,nums,V):
        n=len(nums)
        s=[]
        for j in range(0,n):       #组合列举
            if self.inset(V,j):s.append(nums[j])
        return s

    def inset(self,V,j):        #判断下标j是否在V中
        return (V & (1<<j))!=0
