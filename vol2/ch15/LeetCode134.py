class Solution:
    def canCompleteCircuit(self,gas:List[int],cost:List[int])->int:
        n=len(gas)
        diffsum=0
        for i in range(0,n):
           diffsum+=gas[i]-cost[i]
        if diffsum<0:return -1;   #加油站的汽油总量小于所有的路程
        curgas=0              #记录当前的汽油量
        i,ans=0,0
        while i<n:              #遍历每个加油站
            curgas+=gas[i]-cost[i];    #在加油站i加了gas[i]
            if curgas>=0:i+=1         #油箱的汽油是负数
            else:
                curgas=0           #从加油站i+1重新开始
                ans=i+1
                i+=1
        return ans
