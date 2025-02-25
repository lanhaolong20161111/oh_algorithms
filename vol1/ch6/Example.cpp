#include"btree.cpp"
void levelOrder(TreeNode* root) {
        queue<TreeNode*> qu;
        qu.push(root);                              //根结点进队
        while (!qu.empty()) {                           //队不空循环
		int n=qu.size();							//求出队列中元素个数n
		for(int i=0;i<n;i++) {
            TreeNode*p=qu.front(); qu.pop();            //出队一个结点p
			cout << p->val << " ";					//访问结点p
            if (p->left!=NULL)                      //有左孩子时将其进队
                qu.push(p->left);
            if (p->right!=NULL)                     //有右孩子时将其进队
                qu.push(p->right);
        }
	}
}

vector<int> levelseq(TreeNode* root) {	//二叉树root的层次序列化
	vector<int> s;						//存放序列化序列 
	queue<TreeNode*> qu;									//定义一个队列qu
	qu.push(root);													//根结点进队 
	while (!qu.empty()) {											//队不空循环
		TreeNode* p=qu.front(); qu.pop();					//出队结点p
		if (p!=NULL) {												//结点p非空
			s.push_back(p->val);
			qu.push(p->left);										//左孩子进队（含空的左孩子）
			qu.push(p->right);									//右孩子进队（含空的右孩子）
		}
		else s.push_back(null);									//结点p为空，添加外部结点值
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
            pres+=to_string(root->val)+",";        //数字后面添加一个','
            preorder(root->left,pres);               //产生左子树的序列化序列
            preorder(root->right,pres);              //产生右子树的序列化序列
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
	printf("包含:%d\n",obj.isSubtree(root,subroot)); 


	return 0;
}
	

