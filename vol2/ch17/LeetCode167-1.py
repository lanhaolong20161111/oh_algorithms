class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        n=len(numbers)
        for i in range(0,n):
            low,high=i+1,n-1
            while low<=high:
                mid=(low+high)//2
                if numbers[mid]==target-numbers[i]:
                    return [i+1,mid+1]
                elif target-numbers[mid]<numbers[i]:
                    high=mid-1
                else:
                    low=mid+1
        return [0,0]
