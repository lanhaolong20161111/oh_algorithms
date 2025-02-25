class Solution:
    def minRefuelStops(self,target:int,startFuel:int,stations:List[List[int]])->int:
        n=len(stations)
        pqu=[]                           #大根堆
        ans=0
        pos=0                                  #记录当前到达的位置
        fuel=startFuel                         #当前油量
        i=0
        while i<n:
            if fuel>=stations[i][0]:              #能够到达加油站i
                heapq.heappush(pqu,-stations[i][1]) #将当前加油站的油箱搬走
                i+=1                            #继续行驶
            else:                                  #不能够到达加油站i
                if pqu:
                    fuel+=-heapq.heappop(pqu)     #选择油量最大的加油
                    ans+=1
                else:return -1      #没有油箱时返回-1
        while pqu and fuel<target:    #没有到达目的地时
            fuel+=-heapq.heappop(pqu)     #选择油量最大的加油
            ans+=1
        if fuel>=target:return ans
        return -1
