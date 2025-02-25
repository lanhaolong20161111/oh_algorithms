class Solution:
    def addOperators(self,num: str,target:int) -> List[str]:
        self.ans,self.x=[],""
        self.dfs(num,target,0,0,0)
        return self.ans
    def dfs(self,num,target,i,cursum,prev):
        if i==len(num):
            if cursum==target:
                self.ans.append(str(self.x))
        else:
            oldx=self.x             #临时保存x
            for j in range(i,len(num)):
                if j!=i and num[i]=='0':   #为前导0时返回
                    return
                curs=num[i:j+1]         #取出num[i..j]
                curd=int(curs)
                print(curd)
                if i==0:
                    self.x+=curs
                    self.dfs(num,target,j+1,cursum+curd,curd)
                    self.x=copy.deepcopy(oldx)  #回溯(恢复x)
                else:
                    self.x+='+'+curs
                    self.dfs(num,target,j+1,cursum+curd,curd)
                    self.x=oldx         #回溯(恢复x)
                    self.x+='-'+curs
                    self.dfs(num,target,j+1,cursum-curd,-curd)
                    self.x=oldx         #回溯(恢复x)
                    self.x+='*'+curs
                    self.dfs(num,target,j+1,cursum-prev+prev*curd,prev*curd)
                    self.x=oldx         #回溯(恢复x)
