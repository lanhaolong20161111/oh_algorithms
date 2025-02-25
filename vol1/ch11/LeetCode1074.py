class Solution:
    def numSubmatrixSumTarget(self, matrix: List[List[int]], target: int) -> int:
        m,n=len(matrix),len(matrix[0])
        hmap={}
        ans=0
        for i1 in range(0,m):
            colsum=[0]*n
            for i2 in range(i1,m):
                hmap[0]=1
                cursum=0
                for j in range(0,n):
                    colsum[j]+=matrix[i2][j]
                    cursum+=colsum[j]
                    if cursum-target in hmap:
                        ans+=hmap[cursum-target]
                    if cursum in hmap:hmap[cursum]+=1
                    else:hmap[cursum]=1
                hmap.clear()
        return ans
