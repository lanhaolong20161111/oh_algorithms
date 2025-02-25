class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        n=len(nums)
        nums=list(map(lambda x:x*x,nums))
        mind=min(nums)
        mini=nums.index(mind)
        ans=[]
        ans.append(nums[mini])
        i,j=mini-1,mini+1
        while i>=0 and j<n:
            if nums[i]<=nums[j]:
                ans.append(nums[i])
                i-=1
            else:
                ans.append(nums[j])
                j+=1
        while i>=0:
            ans.append(nums[i])
            i-=1
        while j<n:
            ans.append(nums[j])
            j+=1
        return ans
