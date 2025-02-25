class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        if len(s)!=len(t):
            return False
        hmap1,hmap2={},{}
        for i in range(0,len(s)):
            x,y=s[i],t[i]
            if x not in hmap1 and y not in hmap2:
                hmap1[x],hmap2[y]=y,x
            elif (x in hmap1 and hmap1[x]!=y) or (y in hmap2 and hmap2[y]!=x):
                return False					#不匹配返回false
        return True
