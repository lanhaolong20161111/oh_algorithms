class Solution:
    def consecutiveNumbersSum(self, n: int) -> int:
        ans,k=0,1
        while k*(k+1)<=2*n:
            if self.judge(n, k):ans+=1
            k+=1
        return ans
  
    def judge(self,n,k):
        if k%2==1:      #k为奇数
            return n%k==0
        else:                       #k为偶数
            return n%k!=0 and 2*n%k==0
