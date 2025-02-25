class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        m,n=len(nums1),len(nums2)
        if m>n: return self.intersect(nums2,nums1)
        hmap={}
        for x in nums1:
            if x in hmap:hmap[x]+=1
            else: hmap[x]=1
        ans=[]                    #存放答案
        for y in nums2:
            if y in hmap and hmap[y]>0:
                ans.append(y)
                hmap[y]-=1
        return ans
