class Solution:
    def canReach(self, s:str,minJump:int,maxJump: int)->bool:
        n=len(s)
        if s[n-1]=='1':return False
        presum=[0 for _ in range(n+1)]
        presum[0]=0
        for i in range(1,n+1):
            if s[i-1]=='1':presum[i]=presum[i-1]+1
            else:presum[i]=presum[i-1]
        pqu=[]                  #优先队列（大根堆）
        heapq.heappush(pqu,0)      #从位置0开始跳
        visited=[False for _ in range(n)]
        visited[0]=True
        while pqu:
            i=-heapq.heappop(pqu)
            if i==n-1:return True
            l,r=i+minJump,i+maxJump
            if r<n and presum[r+1]-presum[i]==maxJump:
                return False                 #剪支1
            if r>=n-1 and presum[n]-presum[i]==n-i-1:
                return False
            if r<n and presum[r+1]-presum[l]==maxJump-minJump+1:
                continue;           #剪支2
            j=l;
            while j<=r and j<n:
                if not visited[j] and s[j]=='0':
                    if j==n-1:return True
                    visited[j]=True    #防止重复访问
                    heapq.heappush(pqu,-j)
                j+=1
        return False
