class Codec {
    const char null='#';                                //外部结点值
    int i;												//用于遍历data
public:
    string serialize(TreeNode*root) {          //序列化
       return preorder(root);
    }
    string preorder(TreeNode*root) {
        string pres="";
        if(root==NULL)
            pres=null;
        else {
            pres+=to_string(root->val)+",";        //数字后面添加一个','
            pres+=preorder(root->left);               //产生左子树的序列化序列
            pres+=preorder(root->right);              //产生右子树的序列化序列
        }
        return pres;
    }

    TreeNode* deserialize(string data) {        //反序列化
        i=0;
        return createbt(data); 
    }
    TreeNode*createbt(string&data) {
        if(i>=data.size()) return NULL;
        if(data[i]=='#'){
            i++;
            return NULL;
        }
        TreeNode*root=new TreeNode(getval(data));
        root->left=createbt(data);
        root->right=createbt(data);
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
