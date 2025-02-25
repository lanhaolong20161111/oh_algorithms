class Solution:
    def totalNQueens(self, n: int) -> int:
        x=[i for i in range(0,n)]
        ans=0
        for e in permutations(x):
            if self.isaqueen(n,e):ans+=1
        return ans

    def isaqueen(self,n,x):     #判断x是否是n皇后问题的一个解
        for i in range(1,n):
            if not self.valid(i,x):return False
        return True

    def valid(self,i,x):        #测试(i,x[i])位置是否与前面的皇后不冲突
        if i==0:return True
        k=0
        while k<i:          #k=0～i-1是已放置了皇后的行
            if x[k]==x[i] or abs(x[k]-x[i])==abs(k-i): 
                return False     #(i,x[i])与皇后k有冲突
            k+=1
        return True
