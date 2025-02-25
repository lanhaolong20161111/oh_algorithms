class Solution:
    def flatten(self, root: Optional[TreeNode]) -> None:
        if not root:return                      #空树直接返回
        self.flatten(root.left)
        self.flatten(root.right)
        tmp=root.right                  #临时存放单链表B的首结点
        root.right=root.left
        root.left=None
        p=root
        while p.right!=None:                    #找到单链表A的尾结点p
            p=p.right
        p.right=tmp                         #链接起来
