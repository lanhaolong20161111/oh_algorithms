class Solution:
    def longestValidParentheses(self, s: str) -> int:
        n=len(s)
        if n==0:return 0
        ans=0
        st=[]
        st.append(-1)
        for i in range(0,n):
            if s[i]=='(':
                st.append(i)
            else:
                st.pop()
                if len(st)==0:
                    st.append(i)
                else:
                    ans=max(ans,i-st[-1])
        return ans
