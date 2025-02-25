class Solution:
    def validateStackSequences(self, pushed: List[int], popped: List[int]) -> bool:
        st=[]
        j=0
        for i in range(0,len(pushed)):                   #输入序列没有遍历完
            st.append(pushed[i])                        #pushed[i]进栈
            while len(st)>0 and st[-1]==popped[j]:
                st.pop()                            #popped[j]与栈顶匹配时出栈
                j=j+1
        return len(st)==0                       #栈空返回true;否则返回false       
