class Solution:
  def numOfMinutes(self,n,headID,manager,informTime)->int:
    INF=0x3f3f3f3f
    adj=[[] for _ in range(0,n)]                    #邻接表
    for i in range(0,n):        #建立邻接表
      if manager[i]!=-1:        #i不是总负责人，其直属负责人为manager[i]
        adj[manager[i]].append(i)
    qu=deque()    #定义一个队列，元素为(vno,length)
    qu.append([headID,informTime[headID]])
    ans=0                                #存放答案
    while qu:
      [u,length]=qu.popleft()       #出队
      for v in adj[u]:    #找到u的下属v
        if len(adj[v])==0:         #v是叶子结点
          ans=max(ans,length+informTime[v]) #求总时间的最大值
        else:
          qu.append([v,length+informTime[v]])
    return ans
