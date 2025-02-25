class Solution:
    def nextGreatestLetter(self, letters: List[str], target: str) -> str:	#查找到区间为空
        n=len(letters)
        low,high=0,n-1
        while low<=high:
            mid=(low+high)//2
            if letters[mid]>target:high=mid-1
            else: low=mid+1
        if low>=n:return letters[0]     #未找到target
        else:return letters[low]        #找到target
