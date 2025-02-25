class Solution:
    def splitArray(self, nums: List[int], k: int) -> int:
        low,high=max(nums),sum(nums)
        while low<high:
            mid=(low+high)//2
            cnt=self.Count(nums,mid)
            if cnt<k:           #说明mid大了
                high=mid       #在左区间中继续查找
            else:                #说明mid小了
                low=mid+1     #在右区间中继续查找
        return low
    def Count(self,nums,mid):
        cursum,cnt=0,0
        for i in range(0,len(nums)):   #求以mid为运载能力时对应的天数cnt
            cursum+=nums[i]
            if cursum>mid:
                cnt+=1
                cursum=nums[i]
        return cnt
