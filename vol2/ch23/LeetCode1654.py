class Solution:
    def minimumJumps(self,forbidden:List[int], a:int,b:int,x:int)->int:
        MAXX=6000
        visited=[[False,False] for _ in range(MAXX+1)]
        for e in forbidden:
            visited[e][0],visited[e][1]=True,True
        qu=deque();     #定义一个队列qu,元素为[(当前位置,向后跳次数]
        qu.append([0,0])            #起始点进队
        visited[0][0]=True
        ans=0                     #最少跳跃次数
        while qu:
            cnt=len(qu)
            for i in range(0,cnt):
                [curx,back]=qu.popleft()     #出队
                if curx==x:return ans
                p1=curx+a
                if p1<=MAXX and not visited[p1][0]:
                    visited[p1][0]=True
                    qu.append([p1,0])
                p2=curx-b
                if p2>=0 and back==0 and not visited[p2][0]:
                    visited[p2][1]=True
                    qu.append([p2,1])
            ans+=1
        return -1
