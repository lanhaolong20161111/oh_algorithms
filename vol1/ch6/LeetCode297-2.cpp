class Codec {
    const char null='#';                                //�ⲿ���ֵ
    int i;												//���ڱ���data
public:
    string serialize(TreeNode*root) {          //���л�
       return preorder(root);
    }
    string preorder(TreeNode*root) {
        string pres="";
        if(root==NULL)
            pres=null;
        else {
            pres+=to_string(root->val)+",";        //���ֺ������һ��','
            pres+=preorder(root->left);               //���������������л�����
            pres+=preorder(root->right);              //���������������л�����
        }
        return pres;
    }

    TreeNode* deserialize(string data) {        //�����л�
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
    int getval(string&s) {        //���ִ�ת��Ϊ����
        int d=0,flag=1;
        while(i<s.size() && s[i]!=',') {
            if (s[i]=='-') {
                flag=-1; i++;
            }
            else {
                d=d*10+(s[i]-'0'); i++;
            }
        }
        i++;                    //ͨ�����ִ���β��','
        return flag*d;
    }
};
