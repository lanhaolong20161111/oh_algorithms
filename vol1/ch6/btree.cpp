#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define INF 0x3f3f3f3f
#define null -INF										//表示空结点或者外部结点 
struct TreeNode											//二叉链结点类型 
{	int val;											//结点值（为int类型）
	TreeNode *left;										//左孩子结点指针
	TreeNode *right;									//右孩子结点指针
	TreeNode() : val(0), left(NULL), right(NULL) {}
	TreeNode(int x) : val(x), left(NULL), right(NULL)  {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right)  {}
};
void levelseq(TreeNode* root,vector<int> &s)			//二叉树root的层次序列化
{
	queue<TreeNode*> qu;								//定义一个队列qu
	qu.push(root);										//根结点进队 
	while (!qu.empty())									//队不空循环
	{
		TreeNode* p=qu.front(); qu.pop();				//出队结点p
		if (p!=NULL)									//结点p非空
		{	s.push_back(p->val);
			qu.push(p->left);							//左孩子进队（含空的左孩子）
			qu.push(p->right);							//右孩子进队（含空的右孩子）
		}
		else
			s.push_back(null);							//结点p为空
	}
}
TreeNode* createbtree(vector<int> s) {		//由层次序列化序列s创建二叉链：反序列化
	int n=s.size();
	if (n==0) return NULL;
	TreeNode* root,*p;
	int i=0;								//用i遍历s
	queue<TreeNode*> qu;					//定义一个队列qu 
	root=new TreeNode(s[i++]);				//创建根结点 
	qu.push(root);							//根结点进队 
	while (!qu.empty()) {     						//队不空循环：每次循环访问一层结点
     	p=qu.front(); qu.pop();      		//出队结点p
        if (i<n && s[i]!=null) {					//结点p存在左孩子
			p->left=new TreeNode(s[i++]);		//创建结点p的左孩子
			qu.push(p->left);					//左孩子进队
       	}
       	else {
			p->left=NULL;					//否则置结点p的左孩子为空
		   	i++;
		}
       	if (i<n && s[i]!=null) {					//结点p存在右孩子 
			p->right=new TreeNode(s[i++]);		//创建结点p的右孩子
		   	qu.push(p->right);					//右孩子进队
       	}
     	else {									//否则置结点p的右孩子为空
      		p->right=NULL;
		   	i++;
		}
	}
	return root;
}
void DispBTree(TreeNode* b)							//输出二叉树括号串
{	if (b!=NULL)
	{	printf("%d",b->val);						//输出根结点值
		if (b->left!=NULL || b->right!=NULL)
		{	printf("(");						//有孩子结点时输出"("
			DispBTree(b->left);			//递归输出左子树
			if (b->right!=NULL)
				printf(",");					//有右孩子结点时输出","
			DispBTree(b->right);			//递归输出右子树
			printf(")");						//输出")"
		}
	}
}
void DestroyBTree(TreeNode* &b)						//销毁二叉树
{
	if(b!=NULL)
	{
		DestroyBTree(b->left);
		DestroyBTree(b->right);
		delete b;
		b=NULL;
	}		
}
