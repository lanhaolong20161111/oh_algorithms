class Solution:
    def deleteNode(self,root:Optional[TreeNode],key:int)->Optional[TreeNode]:
        if root==None: return root
        p,f=root,None               #f指向被删结点p的双亲结点
        while p!=None:                               #查找被删结点p
            if p.val==key:break;                     #找到被删结点p时退出循环
            f=p
            if key<p.val: p=p.left
            else: p=p.right
        if p==None:return root                #没有找到被删除结点p，返回root
        if p.left==None and p.right==None:    #结点p是叶子结点
            if p==root:                                #结点p是根结点
                root=None
            else:                                          #结点p不是根结点
                if f.left==p:f.left=None
                else: f.right=None
        elif p.left==None:                    #结点p的左子树为空
            if f==None:                                         #结点p是根结点
                root=root.right  
            else:                                   #结点p不是根结点
                if f.left==p:f.left=p.right
                else: f.right=p.right
        elif p.right==None:                      #结点p的右子树为空
            if f==None:                                         #结点p是根结点
                root=root.left  
            else:                                                      #结点p不是根结点
                if f.left==p:f.left=p.left
                else: f.right=p.left
        else:                                                   #结点p有左右孩子的情况
            q=p.left                                #q指向结点p的左孩子结点
            f=p                            #f指向结点q的双亲结点
            while q.right!=None:                   #找到结点p的左孩子的最右下结点
                f=q
                q=q.right
            p.val=q.val                                 #将结点p的值用结点q的值替换
            if q==f.left:f.left=q.left         #删除结点q
            else: f.right=q.left
        return root
