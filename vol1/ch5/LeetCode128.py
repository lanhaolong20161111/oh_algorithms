class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        hset=set(nums)              #将全部整数存放到hset中
        ans=0                 #存放答案
        for x in hset:
            if x-1 not in hset:    #若x不存在连续的前驱
                y=x                        #以x为起点向后枚举
                while y+1 in hset: y+=1
                ans=max(ans,y-x+1)         #求最大长度
        return ans
