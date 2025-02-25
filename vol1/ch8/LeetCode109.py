class Solution:
    def sortedListToBST(self, head: Optional[ListNode]) -> Optional[TreeNode]:
        ins=[]
        p=head
        while(p!=None):
            ins.append(p.val)
            p=p.next
        return self.preorder(ins,0,len(ins)-1)

    def preorder(self,ins,low,high):
        if low>high: return None
        mid=(low+high)//2
        root=TreeNode(ins[mid])
        root.left=self.preorder(ins,low,mid-1)
        root.right=self.preorder(ins,mid+1,high)
        return root
