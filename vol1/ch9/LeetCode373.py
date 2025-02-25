import heapq
class Solution:
    def kSmallestPairs(self,nums1:List[int],nums2:List[int],k:int)->List[List[int]]:
        m,n=len(nums1),len(nums2)
        ans,pq=[],[]
        for i in range(0,m):        #将有序段0-n-1的首元素进队
            heapq.heappush(pq,[nums1[i]+nums2[0],i,0])
        while k>0 and len(pq)>0:               #循环k次或者队空为止
            e=heapq.heappop(pq)             #出队元素e
            ans.append([nums1[e[1]],nums2[e[2]]])
            if e[2]+1<n:                    #有序段e.i没有超界时
                heapq.heappush(pq,[nums1[e[1]]+nums2[e[2]+1],e[1],e[2]+1])
            k-=1
        return ans
