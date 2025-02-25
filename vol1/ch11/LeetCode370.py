class Solution:
    def getModifiedArray(self,n:int,updates:List[List[int]]) -> List[int]:
        diff=[0]*n
        for i in range(0,len(updates)):
            low=updates[i][0];
            high=updates[i][1];
            c=updates[i][2];
            diff[low]+=c
            if high+1<n:diff[high+1]-=c
        ans=[0]*n
        ans[0]=diff[0]
        for i in range(1,n):
            ans[i]=ans[i-1]+diff[i]
        return ans
