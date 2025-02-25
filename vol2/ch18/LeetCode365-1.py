class Solution:
    def canMeasureWater(self,C1:int,C2:int,T:int) -> bool:
        hset=set((0,0))                                 #用集合判断状态重复

        def dfs(cap1,cap2):                             				#深度优先遍历算法
            if cap1==T or cap2==T or cap1+cap2==T:      #到达目标
                return True
            else:
                if (C1,cap2) not in hset:				#将壶1装满
                    hset.add((C1,cap2)) 
                    if dfs(C1,cap2):return True
                if (cap1,C2) not in hset:                   #将壶2装满
                    hset.add((cap1,C2))
                    if dfs(cap1,C2):return True
                if (0,cap2) not in hset:                    #将壶1清空
                    hset.add((0,cap2))
                    if dfs(0,cap2):return True
                if (cap1,0) not in hset:                    #将壶2清空
                    hset.add((cap1,0))
                    if dfs(cap1,0):return True
                need=min(cap1,C2-cap2)                  #取壶1和壶2剩余空间的最小值
                if (cap1-need,cap2+need) not in hset:
                    hset.add((cap1-need,cap2+need))     #将壶1中的need水倒入壶2
                    if dfs(cap1-need,cap2+need):return True
                need=min(cap2,C1-cap1)                  #取壶2和壶1剩余空间的最小值
                if (cap1+need,cap2-need) not in hset:
                    hset.add((cap1+need,cap2-need))     #将壶2中的need水倒入壶1
                    if dfs(cap1+need,cap2-need):return True
            return False

        return dfs(0,0)
