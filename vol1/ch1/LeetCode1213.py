class Solution:
    def arraysIntersection(self,arr1:List[int],arr2:List[int],arr3:List[int]) -> List[int]:    
        ans=[]
        x=[arr1[0],arr2[0],arr3[0]]
        i,j,k=0,0,0
        while i<len(arr1) and j<len(arr2) and k<len(arr3):
            if x[0]==x[1] and x[1]==x[2]:     #个元素均相等
                if not ans or x[0]!=ans[-1]:
                    ans.append(x[0])
                i,j,k=i+1,j+1,k+1
                if i<len(arr1):x[0]=arr1[i]
                if j<len(arr2):x[1]=arr2[j]
                if k<len(arr3):x[2]=arr3[k]
            else:
                mini=self.minx(x)
                if mini==0:
                    i+=1
                    if i<len(arr1):x[0]=arr1[i]
                elif mini==1:
                    j+=1
                    if j<len(arr2):x[1]=arr2[j]
                else:
                    k+=1
                    if k<len(arr3):x[2]=arr3[k]
        return ans

    def minx(self,x):      #求最小元素的段号
        mini=0
        for i in range(0,3):
            if x[i]<x[mini]:mini=i
        return mini
