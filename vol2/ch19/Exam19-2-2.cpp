#include<iostream>
#include<vector>
using namespace std;
vector<int> x;											//������
int cnt=0;													//�ۼ����и���
void disp() {												//���һ����
	printf("  %2d {",++cnt);
	for (int i=0;i<x.size()-1;i++)
		printf("%d,",x[i]);
	printf("%d}\n",x.back());
}
void dfs(int i) {											//�����㷨
	int n=x.size();
	if (i>=n) {
		disp();
	}
	else {
		for(int j=i;j<n;j++) {								//j��i��n-1ѭ��
			swap(x[i],x[j]);								//����x[i]��x[j]
			dfs(i+1);
			swap(x[i],x[j]);								//���ݣ�����x[i]��x[j]
		}
	}
}
void perm2(vector<int> &a) {							//��ȫ�����㷨2
	int n=a.size();
	x=vector<int>(n);
	for(int i=0;i<n;i++)	x[i]=a[i];						//��x=a
	dfs(0);
}
int main() {
	vector<int> a={1,2,3};
	perm2(a);
	return 0;
}
