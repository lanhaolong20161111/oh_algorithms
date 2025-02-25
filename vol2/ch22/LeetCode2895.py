class Solution:
    def minProcessingTime(self,processorTime:List[int],tasks:List[int])->int:
        processorTime.sort()   #递增排序
        tasks.sort(reverse=True)     #递减排序
        ans=0
        for i in range(0,len(processorTime)):
            ans=max(ans,tasks[4*i]+processorTime[i])
        return ans
