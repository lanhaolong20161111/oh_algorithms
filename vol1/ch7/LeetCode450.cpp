class Solution {
public:
        TreeNode* deleteNode(TreeNode* root, int key) {
            if(root==NULL) return root;
            TreeNode* p=root,*f=NULL;              	//fָ��ɾ���p��˫�׽��
            while(p!=NULL) {                                //���ұ�ɾ���p
                if(p->val==key)  break;                     //�ҵ���ɾ���pʱ�˳�ѭ��
                f=p;
                if(key<p->val) p=p->left;
                else p=p->right;
            }
            if(p==NULL) return root;                //û���ҵ���ɾ�����p������root
            if(p->left==NULL && p->right==NULL) {     //���p��Ҷ�ӽ��
                if(p==root)                                //���p�Ǹ����
                    root=NULL;
                else {                                          //���p���Ǹ����
                    if(f->left==p) f->left=NULL;
                    else f->right=NULL;
                }
                delete p;
            }
            else if (p->left==NULL) {                    //���p��������Ϊ��
            if(f==NULL)                                         //���p�Ǹ����
                root=root->right;  
            else {                                                          //���p���Ǹ����
                if(f->left==p) f->left=p->right;
                else f->right=p->right;
            }
            delete p;
        }
        else if(p->right==NULL) {                      //���p��������Ϊ��
            if(f==NULL)                                         //���p�Ǹ����
                root=root->left;  
            else {                                                      //���p���Ǹ����
                if(f->left==p) f->left=p->left;
                    else f->right=p->left;
                }
                delete p;
            }
            else {                                                   //���p�����Һ��ӵ����
            TreeNode* q=p->left;                                //qָ����p�����ӽ��
                f=p;                                                        //fָ����q��˫�׽��
                while(q->right!=NULL) {                   //�ҵ����p�����ӵ������½��
                    f=q;
                    q=q->right;
                }
                p->val=q->val;                                 //�����p��ֵ�ý��q��ֵ�滻
                if(q==f->left) f->left=q->left;         //ɾ�����q
                else f->right=q->left;
                delete q;
            }
            return root;
    }
};

