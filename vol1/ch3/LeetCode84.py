class Solution:
    def largestRectangleArea(self, a: List[int]) -> int:
        a.append(0)
        n,ans=len(a),0
        st=[]
        for j in range(0,n):
            while st and a[st[-1]]>a[j]:
                k=st[-1]; st.pop()         #退栈tmp
                length=j-st[-1]-1 if st else j
                area=a[k]*length
                ans=max(ans,area)
            st.append(j)
        return ans
