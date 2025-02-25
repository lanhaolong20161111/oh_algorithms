class Solution:
    def nextGreatestLetter(self, letters: List[str], target: str) -> str:	#查找到区间仅含一个元素
        n=len(letters)
        low,high=0,n
        while low<high:
            mid=(low+high)//2
            if letters[mid]>target:high=mid
            else: low=mid+1
        if low>=n:return letters[0]     #未找到target
        else:return letters[low]        #找到target
