class Solution:
    def closestValue(self, root: Optional[TreeNode], target: float) -> int:
        ans=root.val
        while root:
            if abs(root.val-target)<abs(ans-target): ans=root.val
            if target<root.val: root=root.left
            else: root=root.right
        return ans
