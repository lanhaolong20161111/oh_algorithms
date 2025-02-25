from collections import deque
class Solution:
    def countStudents(self, students: List[int], sandwiches: List[int]) -> int:
        qu=deque()
        for stud in students:
            qu.append(stud)
        i=0                #遍历三明治
        cnt=0              #一轮中累计比较的次数
        while len(qu)>0:
            if cnt==len(qu):    #学生队中每个学生都比较一次，则结束
                return len(qu)
            stud=qu.popleft()
            if stud==sandwiches[i]:  #比较成功
                i+=1                    #移到下一个三明治
                cnt=0                  #开始下一轮
            else:                      #比较不超过
                qu.append(stud)          #学生进入队尾
                cnt+=1                  #本轮比较次数增1
        return 0
