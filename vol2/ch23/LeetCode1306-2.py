class Solution:
    def canReach(self,arr:List[int],start:int)->bool:
        n=len(arr)
        if arr[start]==0:return True
        visited=[False for _ in range(n)]
        qu=deque()
        qu.append(start)
        visited[start]=True
        while qu:
            i=qu.popleft()							#出队位置i
            p1=i+arr[i]
            if p1<n and not visited[p1]:
                if arr[p1]==0:return True
                qu.append(p1)
                visited[p1]=True
            p2=i-arr[i]
            if p2>=0 and not visited[p2]:
                if arr[p2]==0:return True
                qu.append(p2)
                visited[p2]=True
        return False
