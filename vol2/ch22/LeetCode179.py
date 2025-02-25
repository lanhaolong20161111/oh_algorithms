class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        a=[str(x) for x in nums]  #将nums转换为字符串数组a
        a.sort(key=functools.cmp_to_key(self.cmp))
        ans=''.join(a)                  #依次合并得到ans
        if ans[0]=='0':return "0"       #处理特殊情况
        else:return ans
    def cmp(self,s,t):             #按指定方式递减排序
        if s+t<t+s:return 1
        else:return -1
