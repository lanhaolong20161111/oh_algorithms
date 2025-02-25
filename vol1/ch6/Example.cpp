#include"btree.cpp"
void levelOrder(TreeNode* root) {
        queue<TreeNode*> qu;
        qu.push(root);                              //��������
        while (!qu.empty()) {                           //�Ӳ���ѭ��
		int n=qu.size();							//���������Ԫ�ظ���n
		for(int i=0;i<n;i++) {
            TreeNode*p=qu.front(); qu.pop();            //����һ�����p
			cout << p->val << " ";					//���ʽ��p
            if (p->left!=NULL)                      //������ʱ�������
                qu.push(p->left);
            if (p->right!=NULL)                     //���Һ���ʱ�������
                qu.push(p->right);
        }
	}
}

vector<int> levelseq(TreeNode* root) {	//������root�Ĳ�����л�
	vector<int> s;						//������л����� 
	queue<TreeNode*> qu;									//����һ������qu
	qu.push(root);													//�������� 
	while (!qu.empty()) {											//�Ӳ���ѭ��
		TreeNode* p=qu.front(); qu.pop();					//���ӽ��p
		if (p!=NULL) {												//���p�ǿ�
			s.push_back(p->val);
			qu.push(p->left);										//���ӽ��ӣ����յ����ӣ�
			qu.push(p->right);									//�Һ��ӽ��ӣ����յ��Һ��ӣ�
		}
		else s.push_back(null);									//���pΪ�գ�����ⲿ���ֵ
	}
	return s; 
}


class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        string preroot="",presubroot="";
        preorder(root,preroot);
        preorder(subRoot,presubroot);
        int i=preroot.find(presubroot);
        if(i!=-1 && (i==0 || preroot[i-1]=='#' || preroot[i-1]==','))
            return true;
        else
            return false;
    }
    void preorder(TreeNode*root,string&pres) {
        if(root==NULL)
            pres.push_back('#');
        else {
            pres+=to_string(root->val)+",";        //���ֺ������һ��','
            preorder(root->left,pres);               //���������������л�����
            preorder(root->right,pres);              //���������������л�����
        }
    }
};

int main() {
	freopen("abc.txt","w",stdout);
	vector<int> s={12,1,3,null,null,2,null,1,3};
	TreeNode*root=createbtree(s);
	printf("root: "); DispBTree(root); printf("\n");
	levelOrder(root); printf("\n");

	vector<int> ans=levelseq(root);
	cout << "ans: ";
	for(int x:ans) {
		if(x==null)
			cout << "#";
		else
			cout << x << ",";
	}
	cout << endl;

	vector<int> t={2,1,3};
	TreeNode*subroot=createbtree(t);
	printf("subroot: "); DispBTree(subroot); printf("\n");
	vector<int> ans1=levelseq(subroot);
	cout << "ans1: ";
	for(int x:ans1) {
		if(x==null)
			cout << "#";
		else
			cout << x << ",";
	}
	cout << endl;
	
	Solution obj;
	printf("����:%d\n",obj.isSubtree(root,subroot)); 


	return 0;
}
	

