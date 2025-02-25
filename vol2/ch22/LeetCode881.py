class Solution:
    def numRescueBoats(self, people: List[int], limit: int) -> int:
        people.sort()       #递增排序
        i,j=0,len(people)-1
        ans=0
        while i<=j:
            if i==j:      #特殊情况：剩下最后一个人单乘
                ans+=1
                break
            if people[i]+people[j]<=limit:  #前后两个人同乘
                ans+=1
                i,j=i+1,j-1
            else:                      #第j个人单乘
                ans+=1
                j-=1
        return ans
