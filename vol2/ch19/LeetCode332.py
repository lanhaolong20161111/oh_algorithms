from collections import defaultdict
class Solution:
    def findItinerary(self,tickets):
        self.hmap=defaultdict(list)				#定义一个字典
        for item in tickets:
            self.hmap[item[0]].append(item[1])
        self.ans=['JFK']
        n=len(tickets)
        self.dfs(n,0)
        return self.ans
    def dfs(self,n,i):
        if i==n:                    #找到一个解
            return True
        else:
            f=self.ans[len(self.ans)-1]     #找到当前出发机场f
            self.hmap[f].sort()             #目的城市递增排序
            for _ in self.hmap[f]:
                t=self.hmap[f].pop(0)  #删除第一个目的城市t
                self.ans.append(t)      #选择第一个目的城市t
                if self.dfs(n,i+1): return True
                self.ans.pop()          #回溯
                self.hmap[f].append(t)
        return False
