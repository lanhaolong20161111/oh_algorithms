class Solution:
    def rangeAddQueries(self, n: int, queries: List[List[int]]) -> List[List[int]]:
        diff=[[0]*(n+1) for i in range(n+1)]
        for i in range(0,len(queries)):
            r1,c1=queries[i][0],queries[i][1]
            r2,c2=queries[i][2],queries[i][3]
            diff[r1][c1]+=1
            diff[r2+1][c2+1]+=1
            diff[r1][c2+1]-=1
            diff[r2+1][c1]-=1
        ans=[[0]*n for i in range(n)]
        ans[0][0]=diff[0][0]
        for i in range(1,n):
            diff[i][0]+=diff[i-1][0]
            ans[i][0]=diff[i][0]
        for j in range(1,n):
            diff[0][j]+=diff[0][j-1]
            ans[0][j]=diff[0][j]
        for i in range(1,n):
            for j in range(1,n):
                diff[i][j]+=diff[i-1][j]+diff[i][j-1]-diff[i-1][j-1]
                ans[i][j]=diff[i][j]
        return ans
