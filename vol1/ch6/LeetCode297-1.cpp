class Codec {
    const char null='#';                                //外部结点值
    int i;                                  //用于遍历data
public:
    string serialize(TreeNode* root) {          //序列化
        string s="";
        if(root==NULL) return s;
        queue<TreeNode*> qu;                            //定义一个队列qu
        qu.push(root);                                  //根结点进队
        while (!qu.empty()) {                           //队不空循环
            TreeNode* p=qu.front(); qu.pop();           //出队结点p
            if (p!=NULL) {  
                s+=to_string(p->val)+",";               //数字后面添加一个','
                qu.push(p->left);                       //左孩子进队（含空的左孩子）
                qu.push(p->right);                      //右孩子进队（含空的右孩子）
            }
            else s+=null;                           //结点p为空，添加外部结点值
        }
        return s;
    }

    TreeNode* deserialize(string data) {        //反序列化
        int n=data.size();
        if (n==0) return NULL;
        TreeNode* root,*p;
        i=0;                                            //用类数据成员i遍历data
        queue<TreeNode*> qu;                                //定义一个队列qu
        root=new TreeNode(getval(data));                          //创建根结点 
        qu.push(root);                      //根结点进队 
        while (!qu.empty()) {       //队不空循环：每次循环访问一层结点
            int m=qu.size();                                        //求队中元素个数m
            for(int j=0;j<m;j++) {                          //出队该层的m个结点
                p=qu.front(); qu.pop();                     //出队结点p
                if (i<n && data[i]!=null) {                         //结点p存在左孩子
                    p->left=new TreeNode(getval(data));           //创建结点p的左孩子
                    qu.push(p->left);                               //左孩子进队
                }
                else {                  //data[i]=null
                    p->left=NULL;                   //否则置结点p的左孩子为空
                    i++;
                }
                if (i<n && data[i]!=null) {                         //结点p存在右孩子 
                    p->right=new TreeNode(getval(data));      //创建结点p的右孩子
                    qu.push(p->right);                          //右孩子进队
                }
                else {                      //data[i]=null
                    p->right=NULL;          //否则置结点p的右孩子为空
                    i++;
                }
            }
        }
        return root;
    }
    int getval(string&s) {        //数字串转换为整数
        int d=0,flag=1;
        while(i<s.size() && s[i]!=',') {
            if (s[i]=='-') {
                flag=-1; i++;
            }
            else {
                d=d*10+(s[i]-'0'); i++;
            }
        }
        i++;                    //通过数字串结尾的','
        return flag*d;
    }
};

