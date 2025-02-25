class Solution:
    def canConstruct(self, s: str, t: str) -> bool:
        if len(s)>len(t): return False
        hmap={}
        for x in t:
            if x in hmap: hmap[x]+=1
            else: hmap[x]=1
        for y in s:
            if y in hmap:hmap[y]-=1
            else:return False					#s中字符y在t中没有出现返回False
        for z in hmap.keys():
            if hmap[z]<0:return False
        return True
