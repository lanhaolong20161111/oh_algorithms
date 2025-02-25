class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
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
