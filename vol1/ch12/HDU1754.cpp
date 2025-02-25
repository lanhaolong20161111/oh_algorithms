#include<iostream>
#include<algorithm>
using namespace std;
#define MAXN 20005
int ST[4*MAXN];							//存放线段树中结点的data值
void Create(int root,int L,int R)			//创建线段树 
{	if(L==R)								//叶子结点
		scanf("%d",&ST[root]);
	else
	{	int mid=(L+R)/2;
		Create(2*root+1,L,mid);				//递归构造左子树
		Create(2*root+2,mid+1,R);			//递归构造右子树
		ST[root]=max(ST[2*root+1],ST[2*root+2]);
    }
}
int Query(int root,int L,int R,int i,int j)	//不考虑延迟情况查询线段树的区间[i..j] 
{	if(R<i || L>j)						//当前结点区间[L..R]与[i..j]没有交集
		return 0;
	if(L>=i && R<=j)						//当前结点区间[L..R]包含在[i..j]中 
		return ST[root];
	int mid=(L+R)/2;						//其他情况 
	int lmax=0,rmax=0;
	if(i<=mid)							//若[i..j]与左孩子有交集 
		lmax=Query(2*root+1,L,mid,i,j);		//递归遍历左子树 
	if(mid<j)								//若[i..j]与右孩子有交集
		rmax=Query(2*root+2,mid+1,R,i,j);	//递归遍历右子树 
	return max(lmax,rmax);
}
void UpdateOne(int root,int L,int R,int idx,int x)  //单点修改:a[idx]=x
{	if(L==R)								//找到一个单点
	{	if(L==idx)						//该单点是要修改的结点
			ST[root]=x;					//直接修改 
		return;
	}
	int mid=(L+R)/2;
	if(idx<=mid)							//在左子树中修改
		UpdateOne(2*root+1,L,mid,idx,x);
	else
		UpdateOne(2*root+2,mid+1,R,idx,x);
	ST[root]=max(ST[2*root+1],ST[2*root+2]);	//根据左右子树的值回溯修改非叶子结点值
}
int main() {
	freopen("abc.txt","r",stdin); 
	int n,m;
	while (~scanf("%d%d",&n,&m))
	{	Create(0,0,n-1);
		while (m--)
		{	char op[2];
			int a,b;
			scanf("%s%d%d",op,&a,&b);
			if (op[0]=='Q')				//Q操作
				printf("%d\n",Query(0,0,n-1,a,b));
			else							//U操作
				UpdateOne(0,0,n-1,a,b);
		}
	}
	return 0;
}

