class Solution:
    def sortColors(self, nums: List[int]) -> None:
        n=len(nums)
        i,j,k=0,-1,n
        while i<k:
            if nums[i]==0: 
                j+=1 
                if i!=j:
                    nums[i],nums[j]=nums[j],nums[i]
                i+=1
            elif nums[i]==2: 
                k-=1
                if i!=k:
                    nums[i],nums[k]=nums[k],nums[i]
            else: i+=1              #nums[i]=1的情况
