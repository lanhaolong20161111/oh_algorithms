class Solution:
    def subsetXORSum(self, nums: List[int]) -> int:
        n,ans=len(nums),0
        for V in range(0,1<<n):
            curs=0
            for j in range(0,n):
                if self.inset(V,j):curs^=nums[j]
            ans+=curs
        return ans

    def inset(self,V,j):    #判断下标j是否在V中
        return (V & (1<<j))!=0
