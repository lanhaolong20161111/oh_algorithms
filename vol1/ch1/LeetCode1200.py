class Solution:
    def minimumAbsDifference(self, arr: List[int]) -> List[List[int]]:
        ans,n=[],len(arr)
        arr.sort()
        mind=arr[n-1]-arr[0]
        for i in range(1,n):
            if arr[i]-arr[i-1]<mind:
                mind=arr[i]-arr[i-1]
                ans=[]
                ans.append([arr[i-1],arr[i]])
            elif arr[i]-arr[i-1]==mind:
                ans.append([arr[i-1],arr[i]])
        return ans
