class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s)!=len(t): return False
        hmap={}
        for x in s:
            if x in hmap: hmap[x]+=1
            else: hmap[x]=1
        for y in t:
            if y in hmap:hmap[y]-=1
        for z in hmap.keys():
            if hmap[z]!=0:return False
        return True
