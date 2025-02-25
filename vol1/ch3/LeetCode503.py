class Solution:
    def nextGreaterElements(self, nums: List[int]) -> List[int]:
        n=len(nums)
        ans=[-1]*n;
        st=[]
        for i in range(0,2*n-1):
            while len(st) and nums[st[-1]]<nums[i%n]:
                ans[st[-1]]=nums[i % n]
                st.pop()
            st.append(i % n);
        return ans
