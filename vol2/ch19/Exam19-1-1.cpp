#include<iostream>
#include<vector>
using namespace std;
vector<int> x;											//������
void disp(vector<int> &a) {						//���һ����
	printf("  {");
	for (int i=0;i<x.size();i++) {
		if (x[i]==1) printf("%d ",a[i]);
	}
	printf("}");
}
void dfs(vector<int> &a,int i) {					//�����㷨
	if (i>=a.size())										//����һ��Ҷ�ӽ��
		disp(a);												//�����Ӧ�Ľ�
	else {
		x[i]=1; dfs(a,i+1);								//ѡ��a[i]
		x[i]=0; dfs(a,i+1);								//��ѡ��a[i]
	}
}
void pset1(vector<int> &a) {						//���ݼ��㷨1
	int n=a.size();
	x=vector<int>(n);
	dfs(a,0);
}
int main() {
	vector<int> a={1,2,3};
	pset1(a);
	return 0;
}
