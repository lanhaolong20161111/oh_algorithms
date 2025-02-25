class QNode:                #优先队列结点类型
    s=""                    #数字字符串
    f,g,h=0,0,0             #启发式函数值
    def __lt__(self,other):     #用于按f越小越优先出队
        if self.f<other.f:return True
        else:return False
class Solution:
    def openLock(self, deadends: List[str], target: str) -> int:
        if target=="0000":return 0
        dead=set()
        for e in deadends:dead.add(e)
        if "0000" in dead:return -1
        pqu=[]
        e=QNode()
        e.s="0000";e.g=0
        e.h=self.geth(e.s,target)
        e.f=e.g+e.h
        heapq.heappush(pqu,e)
        visited=set()
        visited.add("0000")
        while pqu:
            e=heapq.heappop(pqu)          #出队e
            s=e.s
            for ns in self.getnexts(s):
                if ns in visited:continue
                if ns in dead:continue
                if ns==target:return e.g+1      #找到目标
                e1=QNode()
                e1.s=ns; e1.g=e.g+1
                e1.h=self.geth(ns,target)
                e1.f=e1.g+e1.h
                heapq.heappush(pqu,e1)
                visited.add(ns)
        return -1
    def prev(self,x):                #x逆时针方向旋转
        if x=='0':return '9'
        else:return chr(ord(x)-1)
    def succ(self,x):               #顺时针方向旋转
        if x=='9':return '0'
        else:return chr(ord(x)+1)
    def getnexts(self,s):    #枚举s通过一次旋转得到的数字串
        ret=[]
        t=list(s)							#将s转换为字符列表t
        for i in range(0,4):         #旋转每个数字符
            c=t[i]
            t[i]=self.prev(c);               #逆时针方向旋转t[i]
            ret.append(''.join(t))      #旋转结果存入ret
            t[i]=self.succ(c);             #顺时针方向旋转t[i]
            ret.append(''.join(t))             #旋转结果存入ret
            t[i]=c
        return ret
    def geth(self,s,target):     #计算启发函数值
        h=0
        for i in range(0,4):
            dist=abs(int(s[i])-int(target[i]))
            h+=min(dist,10-dist)
        return h
