class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        self.s,x=set(),[]						#s为Python集合，用于除重
        self.dfs(nums,x,0)
        ans=[]
        for e in self.s:						#将集合s中元素添加到ans中
            ans.append(e)
        return ans
    def dfs(self,a,x,i):             				#回溯算法
        if i>=len(a):                                  #到达一个叶子结点
            self.s.add(tuple(x))
        else:
            x.append(a[i])                         	#选择a[i]
            self.dfs(a,x,i+1)
            x.pop()
            self.dfs(a,x,i+1)                         #不选择a[i]
