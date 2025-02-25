class SuffixA:
    MAXN=30010
    def __init__(self,s):
        self.s=s
        self.n=len(s)
        self.cnt=[0]*self.MAXN
        self.sa=[0]*self.MAXN
        self.rank=[0]*self.MAXN
        self.height=[0]*self.MAXN
        self.tmp=[0]*self.MAXN
    def getsa(self):                              #计算后缀数组sa
        n=self.n
        sa=self.sa
        cnt=self.cnt
        rank=self.rank
        s=self.s
        tmp=self.tmp
        maxbuk=256                     #桶个数
        for i in range(0,maxbuk):cnt[i]=0         #桶排序
        for i in range(0,n):cnt[ord(s[i])]+=1
        for i in range(1,maxbuk):cnt[i]+=cnt[i-1]
        for i in range(n-1,-1,-1):sa[cnt[ord(s[i])]-1]=i;cnt[ord(s[i])]-=1
        rank[sa[0]]=0                              #初始排名为0
        num=0                                  #后面排名从1开始
        for i in range(1,n):
            if s[sa[i-1]]==s[sa[i]]:rank[sa[i]]=num 
            else:rank[sa[i]]=num+1;num+=1
        len=1
        while len<n:               #倍增过程
            pos,p=tmp,0                       #当前趟中按y排序后的sa
            for i in range(n-len,n):            #越界y应该排在最前面
                pos[p]=i;p+=1
            for i in range(0,n):
                if sa[i]>=len:                      #未越界y，对应的x为sa[i]-len
                    pos[p]=sa[i]-len;p+=1
            for i in range(0,maxbuk):cnt[i]=0                 #对x进行桶排序
            for i in range(0,n): cnt[rank[pos[i]]]+=1
            for i in range(1,maxbuk):cnt[i]+=cnt[i-1]
            for i in range(n-1,-1,-1):                     #根据桶排序的结果构造后缀数组
                sa[cnt[rank[pos[i]]]-1]=pos[i];cnt[rank[pos[i]]]-=1
            nrank=tmp                    #计算新排名
            nrank[sa[0]]=0
            num=1
            for i in range(1,n):
                if rank[sa[i-1]]==rank[sa[i]] and max(sa[i-1],sa[i])+len<n and rank[sa[i-1]+len]==rank[sa[i]+len]:
                    nrank[sa[i]]=num-1
                else:
                    nrank[sa[i]]=num;num+=1
            for i in range(0,n):rank[i]=nrank[i]            #将nrank复制到rank
            if num>=n: break                               #排名全部确定时结束
            maxbuk=num                                     #修改桶个数
            len=2*len
    def getheight(self):                     #求height数组
        n=self.n
        s=self.s
        sa=self.sa
        rank=self.rank
        height=self.height

        k=0
        for i in range(0,n):
            if rank[i]==0: continue
            if k>0:k-=1
            j=sa[rank[i]-1]
            while j+k<n and i+k<n and s[i+k]==s[j+k]:k+=1
            height[rank[i]]=k
    def solve(self):
        ans=(1+self.n)*self.n//2
        for i in range(0,self.n):ans-=self.height[i]
        return ans

class Solution:
    def countDistinct(self, s: str) -> int:
        sf=SuffixA(s) 
        sf.getsa()
        sf.getheight()
        return sf.solve()
