class Solution:
    def findItinerary(self, tickets: List[List[str]]) -> List[str]:
        self.ans=[]
        hmap={}
        for e in tickets:
            if e[0] in hmap:
                hmap[e[0]].append(e[1])
            else:
                hmap[e[0]]=[e[1]]
        for k in hmap.keys():
            val=hmap[k]
            hmap[k]=sorted(val,reverse=True)   #递减排序
        self.dfs(hmap,"JFK")
        return self.ans[::-1]       #逆置
    def dfs(self,hmap,f):
        while f in hmap and len(hmap[f])>0:
            val=hmap[f]
            t=val[-1]              #找到一个航线[f,t]
            val.pop()               #删除t
            hmap[f]=val
            self.dfs(hmap,t)
        self.ans.append(f)				#逆序插入f
