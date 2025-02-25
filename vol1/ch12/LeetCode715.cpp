struct SNode {
    int val;                    //结点值为区间覆盖长度
    int flag;                   //懒标记
    int left,right;             //左右孩子指针
    SNode():val(0),flag(0),left(-1),right(-1) {}
};
const int MAXN=(int)1e9+10;
class RangeModule {
    vector<SNode> ST;           //存放线段树
    void UpdateRange(int root,int L,int R,int i,int j,int x) {  //x=1表示覆盖，-1表示取消覆盖
        int m=R-L+1;          //区间长度
        if (i<=L && R<=j) {
            ST[root].val=(x==1?m:0);
            ST[root].flag=x;
        }
        else {
            PushDown(root,m);
            int mid=(L+R)>>1;
            if (i<=mid) UpdateRange(ST[root].left,L,mid,i,j,x);
            if (j>mid) UpdateRange(ST[root].right,mid+1,R,i,j,x);
            ST[root].val=ST[ST[root].left].val+ST[ST[root].right].val;
        }
    }
    int QueryRange(int root,int L,int R,int i,int j) {  //区间查询
        if (i<=L && R<=j) return ST[root].val;
        else {
            PushDown(root,R-L+1);
            int mid=(L+R)>>1;
            int ans=0;
            if (i<=mid) ans=QueryRange(ST[root].left,L,mid,i,j);
            if (j>mid) ans+=QueryRange(ST[root].right,mid+1,R,i,j);
            return ans;
        }
    }
    void PushDown(int root,int m) {			//向下传递算法
        if (ST[root].left==-1) {         //动态开点:创建左孩子
            ST.push_back(SNode());
            ST[root].left=ST.size()-1;
        }
        if (ST[root].right==-1) {        //动态开点:创建右孩子
            ST.push_back(SNode());
            ST[root].right=ST.size()-1;
        }
        if (ST[root].flag==0) return;
        if (ST[root].flag==-1)
            ST[ST[root].left].val=ST[ST[root].right].val=0;
        else {
            ST[ST[root].left].val=m-m/2;
            ST[ST[root].right].val=m/2;
        }
        ST[ST[root].left].flag=ST[ST[root].right].flag=ST[root].flag;
        ST[root].flag=0;
    }
public:
    RangeModule() {
        ST.push_back(SNode());       //在线段树中添加根结点ST[0]
     }
    
    void addRange(int left, int right) {
        UpdateRange(0,0,MAXN-1,left,right-1,1);
    }
    
    bool queryRange(int left, int right) {
        return QueryRange(0,0,MAXN-1,left,right-1)==right-left;
    }
    
    void removeRange(int left, int right) {
        UpdateRange(0,0,MAXN-1,left,right-1,-1);
    }
};

