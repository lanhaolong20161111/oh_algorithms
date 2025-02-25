class Codec {
    const char null='#';                                //�ⲿ���ֵ
    int i;                                  //���ڱ���data
public:
    string serialize(TreeNode* root) {          //���л�
        string s="";
        if(root==NULL) return s;
        queue<TreeNode*> qu;                            //����һ������qu
        qu.push(root);                                  //��������
        while (!qu.empty()) {                           //�Ӳ���ѭ��
            TreeNode* p=qu.front(); qu.pop();           //���ӽ��p
            if (p!=NULL) {  
                s+=to_string(p->val)+",";               //���ֺ������һ��','
                qu.push(p->left);                       //���ӽ��ӣ����յ����ӣ�
                qu.push(p->right);                      //�Һ��ӽ��ӣ����յ��Һ��ӣ�
            }
            else s+=null;                           //���pΪ�գ�����ⲿ���ֵ
        }
        return s;
    }

    TreeNode* deserialize(string data) {        //�����л�
        int n=data.size();
        if (n==0) return NULL;
        TreeNode* root,*p;
        i=0;                                            //�������ݳ�Աi����data
        queue<TreeNode*> qu;                                //����һ������qu
        root=new TreeNode(getval(data));                          //��������� 
        qu.push(root);                      //�������� 
        while (!qu.empty()) {       //�Ӳ���ѭ����ÿ��ѭ������һ����
            int m=qu.size();                                        //�����Ԫ�ظ���m
            for(int j=0;j<m;j++) {                          //���Ӹò��m�����
                p=qu.front(); qu.pop();                     //���ӽ��p
                if (i<n && data[i]!=null) {                         //���p��������
                    p->left=new TreeNode(getval(data));           //�������p������
                    qu.push(p->left);                               //���ӽ���
                }
                else {                  //data[i]=null
                    p->left=NULL;                   //�����ý��p������Ϊ��
                    i++;
                }
                if (i<n && data[i]!=null) {                         //���p�����Һ��� 
                    p->right=new TreeNode(getval(data));      //�������p���Һ���
                    qu.push(p->right);                          //�Һ��ӽ���
                }
                else {                      //data[i]=null
                    p->right=NULL;          //�����ý��p���Һ���Ϊ��
                    i++;
                }
            }
        }
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

