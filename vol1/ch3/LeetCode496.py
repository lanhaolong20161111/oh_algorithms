class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        dict={}
        m,n=len(nums1),len(nums2)
        st=[]              #小顶单调栈
        for i in range(0,n):
            while len(st)>0 and st[-1]<nums2[i]:
                dict[st[-1]]=nums2[i]
                st.pop()           #将小于nums[i]的元素出栈
            st.append(nums2[i])
        ans=[-1]*m
        for i in range(0,m):
            if dict.get(nums1[i])==None:
                continue;
            ans[i]=dict.get(nums1[i])
        return ans
