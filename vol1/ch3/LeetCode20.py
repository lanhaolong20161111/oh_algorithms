class Solution:
    def isValid(self, s: str) -> bool:
        n=len(s)
        if n==0:return True
        st=[]
        for i in range(0,n):
            if s[i]=='(' or s[i]=='[' or s[i]=='{':
                st.append(s[i]);
            elif s[i]==')':
                if len(st)==0: return False
                if st[-1]!='(': return False;
                st.pop()
            elif s[i]==']':
                if len(st)==0:return False
                if st[-1]!='[':return False
                st.pop()
            else:                       #s[i]='}'
                if len(st)==0:return False
                if st[-1]!='{': return False
                st.pop()
        return len(st)==0
