class Solution:
    def decodeString(self, s: str) -> str:          #求解算法
        self.i=0                                #类变量i从0开始遍历s
        return self.unfold(s)
    def unfold(self,s):                                         #递归算法
        ans=""
        while self.i<len(s):        						#遍历s
            if s[self.i]>='a' and s[self.i]<='z':       #遇到字母
                ans+=s[self.i]; self.i+=1
            elif s[self.i]>='0' and s[self.i]<='9':     #遇到数字
                k=0
                while self.i<len(s) and s[self.i]>='0' and s[self.i]<='9': 
                    k=k*10+ord(s[self.i])-ord('0');self.i+=1  #将连续的数字符转换为整数k

                self.i+=1                       #数字符后面为'['，跳过该'['
                d=self.unfold(s)                #递归展开后续的(e)得到d
                while k>0:                      #连接d字符串k次
                    ans+=d;k-=1
            else:                           #遇到']'
                self.i+=1                        #跳过']'
                return ans                 #返回该问题的解
        return ans;                                             #s处理完毕返回ans
