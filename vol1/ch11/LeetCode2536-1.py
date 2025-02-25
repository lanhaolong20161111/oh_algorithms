class Solution:
    def rangeAddQueries(self, n: int, queries: List[List[int]]) -> List[List[int]]:
        diff=[[0]*n for i in range(n)]
        for p in range(0,len(queries)):
            r1,c1=queries[p][0],queries[p][1]
            r2,c2=queries[p][2],queries[p][3]
            for i in range(r1,r2+1):
                diff[i][c1]+=1
                if c2+1<n:diff[i][c2+1]-=1
        ans=[[0]*n for i in range(n)]
        for i in range(0,n):
            ans[i][0]=diff[i][0]
        for i in range(0,n):
            for j in range(1,n):
                ans[i][j]=ans[i][j-1]+diff[i][j]
        return ans
