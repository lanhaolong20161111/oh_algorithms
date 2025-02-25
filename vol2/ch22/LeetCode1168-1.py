class Solution:
    def minCostToSupplyWater(self, n:int,wells:List[int],pipes:List[List[int]])->int:
        if n==1:return wells[n-1]
        adj=[[] for _ in range(n+1)] 
        for e in pipes:
          a,b,w=e[0],e[1],e[2]
          adj[a].append([b,w])
          adj[b].append([a,w])
        for i in range(1,n+1):      #建立超级源点0
            adj[0].append([i,wells[i-1]])
            adj[i].append([0,wells[i-1]])
        U=[False for _ in range(n+1)]
        ans=0          #存放答案
        k=0        #累计选择的边数
        pqu=[]          #小根堆，结点类型为[w,vno]
        U[0]=True
        for e in adj[0]:heapq.heappush(pqu,[e[1],e[0]])
        while pqu:
            [w,v]=heapq.heappop(pqu)                #出队
            if U[v]==False:
                U[v]=True
                ans+=w
                k+=1
                if k==n:return ans
                for e in adj[v]:heapq.heappush(pqu,[e[1],e[0]])
        return -1
