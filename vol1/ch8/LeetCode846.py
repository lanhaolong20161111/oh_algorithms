from sortedcontainers import SortedDict
class Solution:
    def isNStraightHand(self, hand: List[int], k: int) -> bool:
        n=len(hand)
        if n%k!=0: return False
        tmap=SortedDict()               #默认递增排列
        for x in hand:						#计数
            if x not in tmap:tmap[x]=1
            else:tmap[x]+=1
        while len(tmap)>0:
            keys=tmap.keys()
            i,x=0,0
            for y in keys:
                if i==k:break
                if i==0:x=y
                if y!=x+i:              #没有找到返回false
                    return False
                tmap[y]-=1              #y长度次数减1
                i+=1
            if i<k:return False         #tmap中整数个数小于k返回False
            tmap=self.removezero(tmap)				#从tmap中删除计数为0的元素
        return True

    def removezero(self,a):             #仅保留tmap中值不为0的元素
        return {key:value for key,value in a.items() if value!=0}
