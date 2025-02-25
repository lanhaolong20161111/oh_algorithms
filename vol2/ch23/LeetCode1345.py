class Solution:
    def minJumps(self, arr: List[int]) -> int:
        n=len(arr)
        hmap=defaultdict(list)
        for i in range(0,n):   #将数组元素值相同的下标放在hmap中
            hmap[arr[i]].append(i)
        visited=set()
        qu=deque()
        qu.append([0,0])
        visited.add(0)
        while qu:
            [p,steps]=qu.popleft()
            if p==n-1:return steps              #找到目标，返回steps
            v=arr[p]
            if v in hmap:                   #处理跳跃方式（3）
                for i in hmap[v]:
                    if i not in visited:
                        visited.add(i)
                        qu.append([i,steps+1])
                del hmap[v]
            p1=p+1                              #处理跳跃方式（1）
            if p1<n and p1 not in visited:
                visited.add(p1)
                qu.append([p1,steps+1])
            p2=p-1                                  #处理跳跃方式（2）
            if p2>=0 and p2 not in visited:
                visited.add(p2)
                qu.append([p2,steps+1])
        return -1
