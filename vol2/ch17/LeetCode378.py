class Solution:
    def kthSmallest(self, matrix: List[List[int]], k: int) -> int:  #查找到区间仅含一个元素
        n=len(matrix)
        low,high=matrix[0][0],matrix[n-1][n-1]
        while low<high:
            mid=low+(high-low)//2
            cnt=self.Count(matrix,mid)
            if cnt>=k:              #说明mid大了
                high=mid              #在左区间中继续查找
            else:                        #说明mid小了
                low=mid+1              #在右区间中继续查找
        return low
    def Count(self,a,mid):
        n=len(a)
        i,j=n-1,0
        cnt=0
        while i>=0 and j<n:
            if a[i][j]<=mid:
                cnt+=i+1
                j+=1
            else:i-=1
        return cnt
