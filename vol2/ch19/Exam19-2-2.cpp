#include<iostream>
#include<vector>
using namespace std;
vector<int> x;											//解向量
int cnt=0;													//累计排列个数
void disp() {												//输出一个解
	printf("  %2d {",++cnt);
	for (int i=0;i<x.size()-1;i++)
		printf("%d,",x[i]);
	printf("%d}\n",x.back());
}
void dfs(int i) {											//回溯算法
	int n=x.size();
	if (i>=n) {
		disp();
	}
	else {
		for(int j=i;j<n;j++) {								//j从i到n-1循环
			swap(x[i],x[j]);								//交换x[i]与x[j]
			dfs(i+1);
			swap(x[i],x[j]);								//回溯：交换x[i]与x[j]
		}
	}
}
void perm2(vector<int> &a) {							//求全排列算法2
	int n=a.size();
	x=vector<int>(n);
	for(int i=0;i<n;i++)	x[i]=a[i];						//置x=a
	dfs(0);
}
int main() {
	vector<int> a={1,2,3};
	perm2(a);
	return 0;
}
