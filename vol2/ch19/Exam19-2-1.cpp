#include<iostream>
#include<vector>
using namespace std;
vector<int> x;										//������
vector<int> used;									//used[i]��ʾa[i]�Ƿ�ʹ�ù�
int cnt=0;												//�ۼ����и���
void disp() {											//���һ����
	printf("  %2d {",++cnt);
	for (int i=0;i<x.size()-1;i++)
		printf("%d,",x[i]);
	printf("%d}\n",x.back());
}
void dfs(vector<int> &a,int i) {					//�����㷨
	int n=a.size();
	if (i>=n) {											//����һ��Ҷ�ӽ��
		disp();
	}
	else {
		for(int j=0;j<n;j++) {						//xi���ܵ�ȡֵΪa[0]-a[n-1]
			if(used[j]) continue;						//��֧�������Ѿ�ʹ�ù���a[j]
			x[i]=a[j];
			used[j]=1;									//ѡ��a[j]
			dfs(a,i+1);								//ת���ռ�������һ��
			used[j]=0;									//����
			x[i]=0;
		}
	}
}
void perm1(vector<int> &a) {						//��ȫ�����㷨1
	int n=a.size();
	x=vector<int>(n);
	used=vector<int>(n,0);
	dfs(a,0);
}
int main() {
	vector<int> a={1,2,3};
	perm1(a);
	return 0;
}
