import heapq
class QNode:									#优先队列结点类
    def __init__(self,val) -> None:
        self.sval=str(val) 

    def __lt__(self,other):					#用于按x+y越大越优先出队
        if self.sval+other.sval>other.sval+self.sval:
            return True
        else:
            return False

class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        maxpq=[]
        for i in range(0,len(nums)):
            heapq.heappush(maxpq,QNode(nums[i]))
        ans=""
        while len(maxpq)>0:
            ans+=maxpq[0].sval
            heapq.heappop(maxpq);
        if ans[0]=='0':return "0"
        else: return ans
