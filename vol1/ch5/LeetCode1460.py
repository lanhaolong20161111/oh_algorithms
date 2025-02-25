class Solution:
    def canBeEqual(self, target: List[int], arr: List[int]) -> bool:
        hmap=dict()
        for x in target:                #计数
            if x in hmap:hmap[x]+=1
            else: hmap[x]=1
        for y in arr:
            if y in hmap:
                if hmap[y]-1<0:
                    return False
                else:hmap[y]-=1
            else:return False
        return True
