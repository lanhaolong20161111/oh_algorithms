class Solution:
    def canMeasureWater(self,C1:int,C2:int,T:int) -> bool:
        qu=deque()                      #定义一个队列
        qu.append([0,0])
        hset=set()    #用哈希集合判断状态重复
        hset.add((0,0))
        while qu:
            [cap1,cap2]=qu.popleft()
            if cap1==T or cap2==T or cap1+cap2==T:
                return True
            if (C1,cap2) not in hset:               #将壶1装满
                hset.add((C1,cap2)) 
                qu.append((C1,cap2))
            if (cap1,C2) not in hset:                   #将壶2装满
                hset.add((cap1,C2))
                qu.append((cap1,C2))
            if (0,cap2) not in hset:                    #将壶1清空
                hset.add((0,cap2))
                qu.append((0,cap2))
            if (cap1,0) not in hset:                    #将壶2清空
                hset.add((cap1,0))
                qu.append((cap1,0))
            need=min(cap1,C2-cap2)                  #取壶1和壶2剩余空间的最小值
            if (cap1-need,cap2+need) not in hset:
                hset.add((cap1-need,cap2+need))     #将壶1中的need水倒入壶2
                qu.append((cap1-need,cap2+need))
            need=min(cap2,C1-cap1)                  #取壶2和壶1剩余空间的最小值
            if (cap1+need,cap2-need) not in hset:
                hset.add((cap1+need,cap2-need))     #将壶2中的need水倒入壶1
                qu.append((cap1+need,cap2-need))
        return False
