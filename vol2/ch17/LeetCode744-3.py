class Solution:
    def nextGreatestLetter(self, letters: List[str], target: str) -> str:		#用Python函数
        i=bisect.bisect_right(letters,target)
        if i>=len(letters): return letters[0];      #未找到target
        else: return letters[i];                #找到target
