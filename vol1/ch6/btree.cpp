#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define INF 0x3f3f3f3f
#define null -INF										//��ʾ�ս������ⲿ��� 
struct TreeNode											//������������� 
{	int val;											//���ֵ��Ϊint���ͣ�
	TreeNode *left;										//���ӽ��ָ��
	TreeNode *right;									//�Һ��ӽ��ָ��
	TreeNode() : val(0), left(NULL), right(NULL) {}
	TreeNode(int x) : val(x), left(NULL), right(NULL)  {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right)  {}
};
void levelseq(TreeNode* root,vector<int> &s)			//������root�Ĳ�����л�
{
	queue<TreeNode*> qu;								//����һ������qu
	qu.push(root);										//�������� 
	while (!qu.empty())									//�Ӳ���ѭ��
	{
		TreeNode* p=qu.front(); qu.pop();				//���ӽ��p
		if (p!=NULL)									//���p�ǿ�
		{	s.push_back(p->val);
			qu.push(p->left);							//���ӽ��ӣ����յ����ӣ�
			qu.push(p->right);							//�Һ��ӽ��ӣ����յ��Һ��ӣ�
		}
		else
			s.push_back(null);							//���pΪ��
	}
}
TreeNode* createbtree(vector<int> s) {		//�ɲ�����л�����s�����������������л�
	int n=s.size();
	if (n==0) return NULL;
	TreeNode* root,*p;
	int i=0;								//��i����s
	queue<TreeNode*> qu;					//����һ������qu 
	root=new TreeNode(s[i++]);				//��������� 
	qu.push(root);							//�������� 
	while (!qu.empty()) {     						//�Ӳ���ѭ����ÿ��ѭ������һ����
     	p=qu.front(); qu.pop();      		//���ӽ��p
        if (i<n && s[i]!=null) {					//���p��������
			p->left=new TreeNode(s[i++]);		//�������p������
			qu.push(p->left);					//���ӽ���
       	}
       	else {
			p->left=NULL;					//�����ý��p������Ϊ��
		   	i++;
		}
       	if (i<n && s[i]!=null) {					//���p�����Һ��� 
			p->right=new TreeNode(s[i++]);		//�������p���Һ���
		   	qu.push(p->right);					//�Һ��ӽ���
       	}
     	else {									//�����ý��p���Һ���Ϊ��
      		p->right=NULL;
		   	i++;
		}
	}
	return root;
}
void DispBTree(TreeNode* b)							//������������Ŵ�
{	if (b!=NULL)
	{	printf("%d",b->val);						//��������ֵ
		if (b->left!=NULL || b->right!=NULL)
		{	printf("(");						//�к��ӽ��ʱ���"("
			DispBTree(b->left);			//�ݹ����������
			if (b->right!=NULL)
				printf(",");					//���Һ��ӽ��ʱ���","
			DispBTree(b->right);			//�ݹ����������
			printf(")");						//���")"
		}
	}
}
void DestroyBTree(TreeNode* &b)						//���ٶ�����
{
	if(b!=NULL)
	{
		DestroyBTree(b->left);
		DestroyBTree(b->right);
		delete b;
		b=NULL;
	}		
}
