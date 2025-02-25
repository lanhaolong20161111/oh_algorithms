class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        n=len(numbers)
        for i in range(0,n-1):
            tmp=numbers[i+1:n]
            it=bisect.bisect_left(tmp,target-numbers[i])
            if it!=len(tmp) and numbers[i]+numbers[it+i+1]==target:
                return [i+1,it+i+2]
        return [0,0]
