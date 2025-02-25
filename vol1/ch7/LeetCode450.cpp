class Solution {
public:
        TreeNode* deleteNode(TreeNode* root, int key) {
            if(root==NULL) return root;
            TreeNode* p=root,*f=NULL;              	//f指向被删结点p的双亲结点
            while(p!=NULL) {                                //查找被删结点p
                if(p->val==key)  break;                     //找到被删结点p时退出循环
                f=p;
                if(key<p->val) p=p->left;
                else p=p->right;
            }
            if(p==NULL) return root;                //没有找到被删除结点p，返回root
            if(p->left==NULL && p->right==NULL) {     //结点p是叶子结点
                if(p==root)                                //结点p是根结点
                    root=NULL;
                else {                                          //结点p不是根结点
                    if(f->left==p) f->left=NULL;
                    else f->right=NULL;
                }
                delete p;
            }
            else if (p->left==NULL) {                    //结点p的左子树为空
            if(f==NULL)                                         //结点p是根结点
                root=root->right;  
            else {                                                          //结点p不是根结点
                if(f->left==p) f->left=p->right;
                else f->right=p->right;
            }
            delete p;
        }
        else if(p->right==NULL) {                      //结点p的右子树为空
            if(f==NULL)                                         //结点p是根结点
                root=root->left;  
            else {                                                      //结点p不是根结点
                if(f->left==p) f->left=p->left;
                    else f->right=p->left;
                }
                delete p;
            }
            else {                                                   //结点p有左右孩子的情况
            TreeNode* q=p->left;                                //q指向结点p的左孩子结点
                f=p;                                                        //f指向结点q的双亲结点
                while(q->right!=NULL) {                   //找到结点p的左孩子的最右下结点
                    f=q;
                    q=q->right;
                }
                p->val=q->val;                                 //将结点p的值用结点q的值替换
                if(q==f->left) f->left=q->left;         //删除结点q
                else f->right=q->left;
                delete q;
            }
            return root;
    }
};

