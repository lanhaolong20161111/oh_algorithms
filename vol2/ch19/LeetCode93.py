class Solution:
    def restoreIpAddresses(self, s: str) -> List[str]:
        self.ans,self.x=[],[0,0,0,0]
        self.dfs(s,0,0)
        return self.ans
    def dfs(self,s,cnt,i):    #回溯算法
        n=len(s)
        if (n-i>(4-cnt)*3) or (n-i<(4-cnt)): #剪支
            return
        if i==n:                      #到达一个叶子结点
            if cnt==4:                #找到一个解
                tmp=""                  #将x转换为字符串
                for j in range(0,4):
                    tmp+=str(self.x[j])
                    if j!=3:tmp+='.'
                self.ans.append(tmp)
        else:
            if s[i]=='0':        #不能有前导零
                self.x[cnt]=0            #若当前为'0'，则这段IP地址只能为0
                self.dfs(s,cnt+1,i+1)
            d=0
            for j in range(i,min(i+3,n)):    #试探j的每个可能的位置
                d=d*10+int(s[j])   
                if d>0 and d<=255:    #剪支
                    self.x[cnt]=d
                    self.dfs(s,cnt+1,j+1)
                else:return            #无效d时回溯
