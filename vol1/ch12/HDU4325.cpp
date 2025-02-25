#include<iostream>
#include<unordered_map>
#include<algorithm>
using namespace std;
const int MAXN=100005;
int ST[4*MAXN];
int flag[4*MAXN];
int X[4*MAXN];
int qu[MAXN];									//表示查询 
int time[MAXN][2];								//表示第i朵花在时间段[time[i][0],time[i][1]]开花 
void Create(int root,int L,int R) {				//创建线段树 
    ST[root]=0;
    flag[root]=0;
    if(L==R) return;
    int mid=(L+R)>>1;
    Create(root*2,L,mid);
    Create(root*2+1,mid+1,R);
}
void PushDown(int root) {									//向下传递算法
	if(flag[root]!=0) {
		ST[2*root]+=flag[root];
		ST[2*root+1]+=flag[root];
		flag[2*root]+=flag[root];
		flag[2*root+1]+=flag[root];
		flag[root]=0;
  	}
}
int QueryOne(int root,int L,int R,int i) {		//单点查询 
    if(L==R)
        return ST[root];
    else {
    	PushDown(root);
    	int mid=(L+R)/2;
    	if(i<=mid)
        	return QueryOne(root*2,L,mid,i);
    	else
        	return QueryOne(root*2+1,mid+1,R,i);
    }
}
void UpdateRange(int root,int L,int R,int i,int j,int color) {	//区间修改 
    if(L>=i && R<=j) {
        ST[root]+=color;
        flag[root]+=color;
    }
    else {
    	PushDown(root);
    	int mid=(L+R)/2;
    	if(j<=mid)
        	UpdateRange(root*2,L,mid,i,j,color);
    	else if(mid<i)
        	UpdateRange(root*2+1,mid+1,R,i,j,color);
    	else {
        	UpdateRange(root*2,L,mid,i,j,color);
        	UpdateRange(root*2+1,mid+1,R,i,j,color);
    	}
    }
}
int main() {
	//freopen("abc.txt","r",stdin);
    int t,n,m,cnt;
    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++) {
        printf("Case #%d:\n",cas);
        scanf("%d%d",&n,&m);
        cnt=0;								//总的时间点个数 
        for(int i=0;i<n;i++) {
            scanf("%d%d",&time[i][0],&time[i][1]);
            X[cnt++]=time[i][0];
            X[cnt++]=time[i][1];
        }
        for(int i=0;i<m;i++) {
            scanf("%d",&qu[i]);
            X[cnt++]=qu[i];
        }       
        sort(X,X+cnt);						//离散化过程 
        unordered_map<int,int> hmap;
        int idx=0;							//不同时间点的个数 
        for(int x:X) {
            if(hmap.count(x)==0) hmap[x]=++idx;
        }
		Create(1,1,idx);
       	for(int i=0;i<n;i++) {
            int s=hmap[time[i][0]];
            int t=hmap[time[i][1]];
            UpdateRange(1,1,idx,s,t,1);
        }
        for(int i=0;i<m;i++) {
            int p=hmap[qu[i]];
            int ans=QueryOne(1,1,idx,p);
            printf("%d\n",ans);
        } 
    }
    return 0;
}
