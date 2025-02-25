class Solution:
    def numOfSubarrays(self, arr: List[int]) -> int:
        MOD=1000000007
        n=len(arr)
        odd,even=0,1
        ans,presum=0,0
        for j in range(0,n):
            presum+=arr[j]
            if presum%2==0:      #前缀和为偶数时
                ans=(ans+odd)%MOD
                even+=1
            else:               #前缀和为奇数时
                ans=(ans+even)%MOD
                odd+=1
        return ans
