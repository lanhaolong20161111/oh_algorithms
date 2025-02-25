#include<iostream>
#include<algorithm>
using namespace std;
#define MAXN 20005
int ST[4*MAXN];							//����߶����н���dataֵ
void Create(int root,int L,int R)			//�����߶��� 
{	if(L==R)								//Ҷ�ӽ��
		scanf("%d",&ST[root]);
	else
	{	int mid=(L+R)/2;
		Create(2*root+1,L,mid);				//�ݹ鹹��������
		Create(2*root+2,mid+1,R);			//�ݹ鹹��������
		ST[root]=max(ST[2*root+1],ST[2*root+2]);
    }
}
int Query(int root,int L,int R,int i,int j)	//�������ӳ������ѯ�߶���������[i..j] 
{	if(R<i || L>j)						//��ǰ�������[L..R]��[i..j]û�н���
		return 0;
	if(L>=i && R<=j)						//��ǰ�������[L..R]������[i..j]�� 
		return ST[root];
	int mid=(L+R)/2;						//������� 
	int lmax=0,rmax=0;
	if(i<=mid)							//��[i..j]�������н��� 
		lmax=Query(2*root+1,L,mid,i,j);		//�ݹ���������� 
	if(mid<j)								//��[i..j]���Һ����н���
		rmax=Query(2*root+2,mid+1,R,i,j);	//�ݹ���������� 
	return max(lmax,rmax);
}
void UpdateOne(int root,int L,int R,int idx,int x)  //�����޸�:a[idx]=x
{	if(L==R)								//�ҵ�һ������
	{	if(L==idx)						//�õ�����Ҫ�޸ĵĽ��
			ST[root]=x;					//ֱ���޸� 
		return;
	}
	int mid=(L+R)/2;
	if(idx<=mid)							//�����������޸�
		UpdateOne(2*root+1,L,mid,idx,x);
	else
		UpdateOne(2*root+2,mid+1,R,idx,x);
	ST[root]=max(ST[2*root+1],ST[2*root+2]);	//��������������ֵ�����޸ķ�Ҷ�ӽ��ֵ
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
			if (op[0]=='Q')				//Q����
				printf("%d\n",Query(0,0,n-1,a,b));
			else							//U����
				UpdateOne(0,0,n-1,a,b);
		}
	}
	return 0;
}

