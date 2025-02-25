class Solution:
    def trap(self, a: List[int]) -> int:
        ans=0
        st=[]
        for i in range(0,len(a)):
            while st and a[st[-1]]<a[i]:
                k=st[-1]; st.pop()
                if len(st)>0:
                    l,r=st[-1],i
                    h=min(a[r],a[l])-a[k]
                    ans+=(r-l-1)*h
            st.append(i)
        return ans
