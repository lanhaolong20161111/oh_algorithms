#include<iostream>
#include<vector>
using namespace std;
const int MAXN=10;
int x[MAXN];										//������
void disp(int i) {									//���һ����
	printf("  {");
	for (int k=0;k<i;k++)
		printf("%d ",x[k]);
	printf("}");
}
void dfs(vector<int> &a,int i,int j) {			//�����㷨
	disp(i);												//���һ����x[0..i-1]
	for(int j1=j;j1<a.size();j1++) {
		x[i]=a[j1];
		dfs(a,i+1,j1+1);
		x[i]=-1;											//����
	}
}
void pset2(vector<int> &a) {					//���ݼ��㷨2
	dfs(a,0,0);
}
int main() {
	vector<int> a={1,2,3};
	pset2(a);
	return 0;
}
