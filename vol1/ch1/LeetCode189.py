class Solution:
    def rotate(self, nums, k: int) -> None:
        n=len(nums)
        if n==1: return
        k=k%n
        self.reverse(nums,0,n-k-1)
        self.reverse(nums,n-k,n-1)
        self.reverse(nums,0,n-1)

    def reverse(self,nums,s,t):
        i,j=s,t
        while i<j:
            nums[i],nums[j]=nums[j],nums[i]
            i+=1; j-=1



class Solution:
    def rotate(self, nums,k:int):
        n=len(nums)
        if n==1: return
        k=k%n
        tmp=nums[n-k-1::-1]+nums[n-1:n-k-1:-1]
        tmp.reverse()
        nums[:]=tmp[:]
