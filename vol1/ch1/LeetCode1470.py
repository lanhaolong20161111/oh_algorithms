class Solution:
    def shuffle(self, nums: List[int], n: int) -> List[int]:
        ans=[]
        i,j=0,n
        while i<n:
            ans.append(nums[i])
            ans.append(nums[j])
            i+=1; j+=1
        return ans