class Solution:
    def maxEnvelopes(self,envelopes:List[List[int]]) -> int:
        n=len(envelopes)
        envelopes.sort(key=lambda x:(x[0],-x[1]))
        height=[]
        for e in envelopes:height.append(e[1])
        return self.lengthOfLIS(height)
    def lengthOfLIS(self, nums: List[int]):			#求最长递增子序列的长度
        n=len(nums)
        ans=[nums[0]]
        for i in range(1,n):
            curd=nums[i]
            if curd>ans[-1]:        #大于ans中最大数时直接添加
                ans.append(curd)
            else:
                j=bisect.bisect_left(ans,curd)
                ans[j]=curd         #替换
        return len(ans)
