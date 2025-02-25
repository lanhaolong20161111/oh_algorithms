class Solution:
    def getPermutation(self, n: int, k: int) -> str:
        x=[i for i in range(1,n+1)]
        cnt=0
        for e in permutations(x):
            cnt+=1
            if cnt==k:break;
        ret=""
        for d in e:
            ret+=str(d)
        return ret 
