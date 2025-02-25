class Solution:
    def canReach(self,arr:List[int],start:int)->bool:
        n=len(arr)
        self.visited=[False for _ in range(n)]
        return self.dfs(arr,start)
    def dfs(self,arr,i):
        if i<0 or i>=len(arr):
            return False
        if self.visited[i]:return False
        if arr[i]==0:return True
        self.visited[i]=True
        if self.dfs(arr,i+arr[i]):return True
        if self.dfs(arr,i-arr[i]): return True
        return False
