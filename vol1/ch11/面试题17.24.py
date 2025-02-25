class Solution:
    def getMaxMatrix(self, matrix: List[List[int]]) -> List[int]:
        m,n=len(matrix),len(matrix[0])
        presum=[[0]*(n+1) for i in range(m+1)]
        for i in range(1,m+1):
            for j in range(1,n+1):
                presum[i][j]=presum[i][j-1]+presum[i-1][j]-presum[i-1][j-1]+matrix[i-1][j-1]
        ans,maxsum=[],-0x3f3f3f3f
        for i1 in range(0,m):
            for i2 in range(i1,m):
                cursum,j1=0,0
                for j2 in range(0,n):
                    cursum=presum[i2+1][j2+1]+presum[i1][j1]-presum[i2+1][j1]-presum[i1][j2+1]
                    if cursum>maxsum:
                        maxsum=cursum
                        ans=[i1,j1,i2,j2]
                    if cursum<0:j1=j2+1
        return ans
