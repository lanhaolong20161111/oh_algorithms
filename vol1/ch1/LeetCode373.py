class Solution:
    def __init__(self):                     #构造函数
        self.INF=0x3f3f3f3f

    def kSmallestPairs(self, nums1:List[int],nums2:List[int],k:int) -> List[List[int]]:
        m,n=len(nums1),len(nums2)
        ans=[]
        x=[None]*m
        for i in range(0,m):
            x[i]=[i,0,nums1[i]+nums2[0]]
        while k>0:
            mini=self.mink(nums1,nums2,x)
            if mini==-1:break;
            i,j=nums1[x[mini][0]],nums2[x[mini][1]]
            ans.append([i,j])
            if x[mini][1]+1<n:
                i,j=x[mini][0],x[mini][1]+1
                x[mini]=[i,j,nums1[i]+nums2[j]]
            else: 
                x[mini]=[-1,-1,self.INF]
            k-=1
        return ans

    def mink(self,a,b,x):
        mini=0
        for k in range(1,len(x)):
            if x[k][2]<x[mini][2]:  mini=k
        if x[mini][2]==self.INF: return -1
        else:  return mini
