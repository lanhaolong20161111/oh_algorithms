class Solution:
    def verifyPreorder(self, pres: List[int]) -> bool:
        n=len(pres)
        st=[]                                   #单调递减栈
        rootd=-1                                 #初始化为最小元素值
        for i in range(0,n):
            if pres[i]<rootd: return False
            while st and pres[i]>st[-1]:
                rootd=st.pop()               #将小于pres[i]的栈顶元素出栈
            st.append(pres[i])                          #pres[i]进栈
        return True
