class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        n=len(temperatures)
        ans=[0]*n
        st=[]
        for i in range(0,n):
            while st and temperatures[st[-1]]<temperatures[i]:
                prei=st[-1]
                ans[prei]=i-prei
                st.pop()
            st.append(i)
        return ans 