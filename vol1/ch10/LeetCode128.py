class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        self.FLAG=0x3f3f3f3f
        self.parent={}    #记录每个结点的父结点
        self.cnt={}         #子树中的整数个数
        self.Init(nums)
        n=len(nums)
        for i in range(0,n):
            if self.Find(nums[i]+1)!=self.FLAG:  #当存在nums[i]+1
                self.Union(nums[i],nums[i]+1)   #将其合并
        ans=0
        for i in range(0,n):         #求最多的子树结点个数
            ans=max(ans,self.cnt[nums[i]])
        return ans

    def Init(self,nums):              #并查集初始化
        for i in range(0,len(nums)):
            self.parent[nums[i]]=nums[i]
            self.cnt[nums[i]]=1

    def Find(self,x):                          #递归算法：并查集中查找x结点的根结点
        if x not in self.parent:  #nums不包含x
            return self.FLAG
        if x!=self.parent[x]:
            self.parent[x]=self.Find(self.parent[x])          #路径压缩
        return self.parent[x];

    def Union(self,x,y):                     #并查集中x和y的两个集合的合并
        rx,ry=self.Find(x),self.Find(y)
        if rx==ry: return;                       #x和y属于同一棵树的情况
        self.parent[rx]=ry
        self.cnt[ry]+=self.cnt[rx]
