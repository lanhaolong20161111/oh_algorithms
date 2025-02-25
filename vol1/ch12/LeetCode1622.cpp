const int MAXN=100005;
const int MOD=1000000007;
struct SNode {							//线段树结点类型
    int val;        //原数
    int add;        //增数add数
    int mul;        //倍数mul数
    int left,right;
    SNode():add(0),mul(1),left(-1),right(-1) {}
};
class Fancy {
    vector<SNode> ST;
    int end;                        //添加元素的位置（添加的元素个数）
    int addv(int a,int b) {			//加模运算
        return (int) ((1l*a+1l*b) % MOD);
    }

    void PushDown(int root) {           //向下传递算法
        if(ST[root].left==-1) {        //动态开点:创建左孩子
            ST.push_back(SNode());
            ST[root].left=ST.size()-1;
        }
        if(ST[root].right==-1) {        //动态开点:创建右孩子
            ST.push_back(SNode());
            ST[root].right=ST.size()-1;
        }
        if(ST[root].add==0 && ST[root].mul==1) return;
        ST[ST[root].left].mul=mulv(ST[root].mul,ST[ST[root].left].mul);
        ST[ST[root].right].mul=mulv(ST[root].mul,ST[ST[root].right].mul);
        ST[ST[root].left].add=mulv(ST[root].mul,ST[ST[root].left].add);
        ST[ST[root].right].add=mulv(ST[root].mul,ST[ST[root].right].add);
        ST[root].mul=1;
        ST[ST[root].left].add=addv(ST[root].add,ST[ST[root].left].add);
        ST[ST[root].right].add=addv(ST[root].add,ST[ST[root].right].add);
        ST[root].add=0;
    }

    void addRange(int root,int L,int R,int i,int j,int val) {   //区间加法修改
        if (i>j) return;
        if (i<=L && R<=j)
            ST[root].add=addv(ST[root].add,val);
        else {
            PushDown(root);
            int mid=(L+R)/2;
            if (i<=mid) addRange(ST[root].left,L,mid,i,j,val);
            if (j>mid) addRange(ST[root].right,mid+1,R,i,j,val);
        }
    }
    int mulv(int a,int b) {				//乘模运算
        return (int) (1l*a*b % MOD);
    }

    void mulRange(int root,int L, int R,int i, int j, int val) { //区间乘法修改
        if (i>j) return;
        if (i<=L && R<=j) {
            ST[root].add=mulv(ST[root].add,val);
            ST[root].mul=mulv(ST[root].mul,val);
        }
        else {
            PushDown(root);
            int mid=(L+R)/2;
            if (i<=mid) mulRange(ST[root].left,L,mid,i,j, val);
            if (j>mid) mulRange(ST[root].right,mid+1,R,i,j,val);
        }
    }

    int Query(int i) {                      //查询
        int id=QueryOne(0,0,MAXN-1,i);          //找到累积，累和的索引
        return addv(mulv(ST[i].val,ST[id].mul),ST[id].add); //原数*累积+累和
    }

    int QueryOne(int root,int L,int R,int i) {  //单点查询
        if (L==R) return root;
        else {
            PushDown(root);
            int mid=(L+R)/2;
            if (i<=mid) return QueryOne(ST[root].left,L,mid,i);
            else return QueryOne(ST[root].right,mid+1,R,i);
        }
    }
public:
    Fancy() {
        ST.push_back(SNode());       //在线段树中添加根结点ST[0]
        end=0;
    }
    
    void append(int val) {
        ST.push_back(SNode());
        ST[end++].val=val;
    }
    
    void addAll(int inc) {
        addRange(0,0,MAXN-1,0,end-1,inc);
    }
    
    void multAll(int m) {
        mulRange(0,0,MAXN-1,0,end-1,m);
    }
    
    int getIndex(int idx) {
        if (idx>=end) return -1;
        return Query(idx);
    }
};
