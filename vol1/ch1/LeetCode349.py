class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        nums1.sort()
        nums2.sort()
        ans=[]
        i,j=0,0
        while i<len(nums1) and j<len(nums2):
            if nums1[i]<nums2[j]:
                i+=1
            elif nums1[i]>nums2[j]:
                j+=1
            else:     
                if not ans or nums1[i]!=ans[-1]:
                    ans.append(nums1[i])
                i,j=i+1,j+1
        return ans