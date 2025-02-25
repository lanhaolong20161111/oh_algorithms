import heapq
class Solution:
    def maxPerformance(self, n:int,speed:List[int],efficiency:List[int],k:int)->int:
        enger=[]
        for i in range(0,n):
            enger.append([efficiency[i],speed[i]])
        enger.sort(key=lambda x:x[0],reverse=True)  #按e递减排序
        minpq=[]            #按s越小越优先出队
        ans=0; sum=0
        for i in range(0,n):
            if len(minpq)>k-1:
                sum-=minpq[0]     #递减sum
                heapq.heappop(minpq)            #当前区间中最小s出堆
            sum+=enger[i][1]             #当前区间必须包含enger[i]
            eff=enger[i][0]
            ans=max(ans,sum*eff)
            heapq.heappush(minpq,enger[i][1])
        return ans % 1000000007
