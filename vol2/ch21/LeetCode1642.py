class Solution:
    def checkIfPrerequisite(self,n:int,prereqs,ques) -> List[bool]:
        A=[[False for _ in range(n)] for _ in range(n)]
        for e in prereqs:
            a,b=e[0],e[1]
            A[a][b]=True
        for k in range(0,n):
            for i in range(0,n):
                for j in range(0,n):
                    A[i][j]=A[i][j] or (A[i][k] and A[k][j])
        ans=[]
        for e in ques:
            u,v=e[0],e[1]
            ans.append(A[u][v])
        return ans
