class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        n=len(nums)
        if n==1:return nums[0]
        return self.majore(nums,0,n-1);
    def majore(self,nums,low,high):
        if low==high:return nums[low]
        mid=(low+high)//2
        leftmaj=self.majore(nums,low,mid)
        rightmaj=self.majore(nums,mid+1,high)
        if leftmaj==rightmaj:
            return leftmaj
        else:
            leftcnt=0
            for i in range(low,high+1):
                if nums[i]==leftmaj:leftcnt+=1
            rightcnt=0
            for i in range(low,high+1):
                if nums[i]==rightmaj:rightcnt+=1
            if leftcnt>rightcnt:return leftmaj
            else:return rightmaj
