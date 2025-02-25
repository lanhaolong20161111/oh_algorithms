class Solution:
    def minRemoveToMakeValid(self, s: str) -> str:
        st=[]
        for i in range(0,len(s)):
            ch=s[i]
            if ch=='(':
                st.append(i)
            elif ch==')':
                if  len(st)>0 and s[st[-1]]=='(':
                    st.pop()
                else:
                    st.append(i)
        ns=list(s)
        while len(st)>0:
            i=st[-1]; st.pop()
            ns.pop(i)
        return ''.join(ns)
