class Solution:
    def simplifyPath(self,path:str)->str:
        words=path.split("/")
        st=[]
        for word in words:
            if word=='.': continue;
            elif word=="..":
                if st:st.pop()
            elif len(word)>0:
                st.append(word)
        return "/"+"/".join(st)
