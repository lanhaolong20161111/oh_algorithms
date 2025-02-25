from sortedcontainers import SortedList
class Player:
    def __init__(self,i,m):
        self.i=i                #运动员编号
        self.mark=m             #运动员成绩
    
    def __lt__(self,other): 
        if self.mark>other.mark:
            return True					 #指定按mark越大越优先
        else:
            return False

class Solution:
    def findRelativeRanks(self, score: List[int]) -> List[str]:
        n=len(score)
        tset=SortedList()
        for i in range(0,n):
            tset.add(Player(i,score[i]))
        ans=[None]*n
        i=1
        for c in tset:
            if i==1:ans[c.i]="Gold Medal"
            elif i==2:ans[c.i]="Silver Medal"
            elif i==3:ans[c.i]="Bronze Medal"
            else: ans[c.i]=str(i)
            i+=1
        return ans
