class Solution:
  def findShortestCycle(self,n:int,edges:List[List[int]])->int:
    INF=1005
    M=[[INF for _ in range(n)] for _ in range(n)]
    for e in edges:
      a,b=e[0],e[1]
      M[a][b],M[b][a]=1,1
    A=copy.deepcopy(M)
    ans=INF
    for k in range(0,n):
      for i in range(0,k):
        for j in range(i+1,k):
          ans=min(ans,A[i][j]+M[j][k]+M[k][i])
      for i in range(0,n):
        for j in range(0,n):
          A[i][j]=min(A[i][j],A[i][k]+A[k][j])
    if ans>=INF:return -1
    return ans
