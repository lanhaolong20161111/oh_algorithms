class Solution:
    def shipWithinDays(self, weights: List[int], D: int) -> int:	#查找到区间仅含一个元素
        low,high=max(weights),sum(weights)
        while low<high:
            mid=(low+high)//2
            cnt=self.Count(weights,mid)
            if cnt<D:           #说明mid大了
                high=mid       #在左区间中继续查找
            else:                #说明mid小了
                low=mid+1     #在右区间中继续查找
        return low
    def Count(self,weights,mid):
        cursum,cnt=0,0
        for i in range(0,len(weights)):   #求以mid为运载能力时对应的天数cnt
            cursum+=weights[i]
            if cursum>mid:
                cnt+=1
                cursum=weights[i]
        return cnt
