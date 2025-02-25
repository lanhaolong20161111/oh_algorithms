class Solution:
    def nthUglyNumber(self, n: int) -> int:
        ans=[0]*(n+1)
        ans[1]=1
        p2,p3,p5=1,1,1
        for i in range(2,n+1):
            a=ans[p2]*2
            b=ans[p3]*3
            c=ans[p5]*5
            mind=min(a,min(b,c))    			#求a,b,c中最小整数mind
            if mind==a: p2+=1
            if mind==b: p3+=1
            if mind==c: p5+=1
            ans[i]=mind
        return ans[n]
