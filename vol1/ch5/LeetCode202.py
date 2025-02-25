class Solution:
    def isHappy(self, n: int) -> bool:
        hset=set()
        while n!=1 and n not in hset:
            hset.add(n)
            n=self.getnext(n)
        return n==1

    def getnext(self,m):
        ans=0
        while m>0:
            tmp=m%10
            ans+=tmp*tmp
            m=m//10
        return ans
