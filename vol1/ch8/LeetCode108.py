class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> Optional[TreeNode]:
         return self.preorder(nums,0,len(nums)-1)

    def preorder(self,nums,low,high):
        if low>high: return None
        mid=(low+high)//2
        root=TreeNode(nums[mid])
        root.left=self.preorder(nums,low,mid-1)
        root.right=self.preorder(nums,mid+1,high)
        return root
