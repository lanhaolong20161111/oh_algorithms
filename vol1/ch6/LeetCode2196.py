class Solution:
    def createBinaryTree(self, descriptions: List[List[int]]) -> Optional[TreeNode]:
        dict={}
        root=None
        for v in descriptions:
            dict[v[1]]=TreeNode(v[1])  #创建所有的子结点
        for v in descriptions:
            if not v[0] in dict:       #找根结点
                dict[v[0]]=TreeNode(v[0])
                root=dict[v[0]]
            if v[2]==1:                     #建立父子关系
                dict[v[0]].left=dict[v[1]]
            else:
                dict[v[0]].right=dict[v[1]]
        return root
