#include<iostream>
#include<vector>
using namespace std;
vector<int> x;										//解向量
vector<int> used;									//used[i]表示a[i]是否使用过
int cnt=0;												//累计排列个数
void disp() {											//输出一个解
	printf("  %2d {",++cnt);
	for (int i=0;i<x.size()-1;i++)
		printf("%d,",x[i]);
	printf("%d}\n",x.back());
}
void dfs(vector<int> &a,int i) {					//回溯算法
	int n=a.size();
	if (i>=n) {											//到达一个叶子结点
		disp();
	}
	else {
		for(int j=0;j<n;j++) {						//xi可能的取值为a[0]-a[n-1]
			if(used[j]) continue;						//剪支：跳过已经使用过的a[j]
			x[i]=a[j];
			used[j]=1;									//选择a[j]
			dfs(a,i+1);								//转向解空间树的下一层
			used[j]=0;									//回溯
			x[i]=0;
		}
	}
}
void perm1(vector<int> &a) {						//求全排列算法1
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
