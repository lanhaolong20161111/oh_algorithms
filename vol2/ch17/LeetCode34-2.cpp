class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        f=bisect.bisect_left(nums,target)
        if f>=len(nums) or nums[f]!=target:             #Ã»ÓĞÕÒµ½target 
            return [-1,-1]
        e=bisect.bisect_right(nums,target)
        return [f,e-1]

