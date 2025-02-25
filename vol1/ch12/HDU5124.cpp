#include<stdio.h>
#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
#include <cstring>
using namespace std;
const int MAX=1000000;
 
int arr[500005][2];
vector<int> v;
unordered_map<int,int> mp;
struct pr {
    int sum;
    int lazy;
    int left,right;					//对应区间，注意区别rr,ll
}tr[MAX+10];
int n;
inline int ll(int k) {return 2*k;} 		 //左边的下标
inline int rr(int k) {return 2*k+1;}		 //右边的下标
inline int mid(int kk1,int kk2) {return (kk1+kk2)>>1;}
void pushdown(int k) {
    if (tr[k].lazy) {							//如果是加，则变成+=
        tr[ll(k)].sum+=tr[k].lazy*(tr[ll(k)].right-tr[ll(k)].left+1);
        tr[rr(k)].sum+=tr[k].lazy*(tr[rr(k)].right-tr[rr(k)].left+1);
        tr[ll(k)].lazy+=tr[k].lazy;
        tr[rr(k)].lazy+=tr[k].lazy;
        tr[k].lazy=0;
    }
}
 
void build(int k,int s,int t) {
    tr[k].left=s;tr[k].right=t;
    if(s==t) {tr[k].sum=0;return;}				//开始最下面是多少
    build(ll(k),s,mid(s,t));
    build(rr(k),mid(s,t)+1,t);
    tr[k].sum=tr[ll(k)].sum+tr[rr(k)].sum;		//如果是最大就是max
}
 
void modify(int k,int s,int t,int x) {
    int l=tr[k].left,r=tr[k].right;
    if(l==s&&r==t) {		//(l==s&&r==t)
        tr[k].lazy+=x;
        tr[k].sum+=x*(r-l+1);
        return ;
    }
    pushdown(k);
    int mi=mid(l,r);
    if(t<=mi) modify(ll(k),s,t,x);
    else if(s>mi) modify(rr(k),s,t,x);
    else {
        modify(ll(k),s,mi,x);
        modify(rr(k),mi+1,t,x);
    }
    tr[k].sum=tr[ll(k)].sum+tr[rr(k)].sum;
}
 
int query(int k,int s,int t) {
    int l=tr[k].left,r=tr[k].right;
    if(l==s&&r==t) return tr[k].sum;
    pushdown(k);
    int mi=mid(l,r);
    int res=0;
    if (t<=mi) res+=query(ll(k),s,t);
    else if(s>mi) res+=query(rr(k),s,t);
    else res+=query(ll(k),s,mi)+query(rr(k),mi+1,t);
    return res;
}
 
int main()
{
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        mp.clear();
        v.clear();
        memset(tr,0,sizeof(tr));
        for(int i=0;i<n;i++){
            scanf("%d%d",&arr[i][0],&arr[i][1]);
            v.push_back(arr[i][0]);
            v.push_back(arr[i][1]);
        }
        sort(v.begin(),v.end());
        int nn=(int)(unique(v.begin(),v.end())-v.begin());
        int ans=0;
        for(int i=0;i<nn;i++){
            mp[v[i]]=i+1;
        }
        unordered_map<int,int>::iterator it=mp.begin();
        build(1,1,nn);
        for(int i=0;i<n;i++){
            modify(1,mp[arr[i][0]],mp[arr[i][1]],1);
        }
        for(int i=1;i<=nn;i++){
            ans=max(ans,query(1,i,i));
        }
        cout<<ans<<endl;
    }
    return 0;
}
