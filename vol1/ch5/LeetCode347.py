import heapq
class Solution:
    def topKFrequent(self, nums, k: int):
        hmap={}
        for i in range(len(nums)):      #累计每个整数出现的次数
            if nums[i] in hmap:hmap[nums[i]]+=1
            else: hmap[nums[i]]=1
        heap=[]
        for key,cnt in hmap.items():     #按cnt建立大根堆
            heapq.heappush(heap,[-cnt,key])
        ans=[]
        for i in range(k):              #求前k高的元素
            e=heapq.heappop(heap)
            ans.append(e[1])
        return ans
