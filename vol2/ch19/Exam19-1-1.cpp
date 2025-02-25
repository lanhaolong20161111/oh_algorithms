#include<iostream>
#include<vector>
using namespace std;
vector<int> x;											//解向量
void disp(vector<int> &a) {						//输出一个解
	printf("  {");
	for (int i=0;i<x.size();i++) {
		if (x[i]==1) printf("%d ",a[i]);
	}
	printf("}");
}
void dfs(vector<int> &a,int i) {					//回溯算法
	if (i>=a.size())										//到达一个叶子结点
		disp(a);												//输出对应的解
	else {
		x[i]=1; dfs(a,i+1);								//选择a[i]
		x[i]=0; dfs(a,i+1);								//不选择a[i]
	}
}
void pset1(vector<int> &a) {						//求幂集算法1
	int n=a.size();
	x=vector<int>(n);
	dfs(a,0);
}
int main() {
	vector<int> a={1,2,3};
	pset1(a);
	return 0;
}
