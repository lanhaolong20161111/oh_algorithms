const int MAXN=100005;
const int MOD=1000000007;
struct SNode {							//线段树结点类型
    int val;        //原数
    int add;        //增数add数
    int mul;        //倍数mul数
    SNode():add(0),mul(1) {}
};
class Fancy {
    vector<int> a;							//存放添加的整数序列
    vector<SNode> ST;

    int addv(int a,int b) {			//加模运算
        return (int) ((1l*a+1l*b) % MOD);
    }

    void PushDown(int root) {           //向下传递算法
        if(ST[root].add==0 && ST[root].mul==1) return;
        ST[2*root+1].mul=mulv(ST[root].mul,ST[2*root+1].mul);
        ST[2*root+2].mul=mulv(ST[root].mul,ST[2*root+2].mul);
        ST[2*root+1].add=mulv(ST[root].mul,ST[2*root+1].add);
        ST[2*root+2].add=mulv(ST[root].mul,ST[2*root+2].add);
        ST[root].mul=1;
        ST[2*root+1].add=addv(ST[root].add,ST[2*root+1].add);
        ST[2*root+2].add=addv(ST[root].add,ST[2*root+2].add);
        ST[root].add=0;
    }

    void addRange(int root,int L,int R,int i,int j,int val) {   //区间加法修改
        if (i>j) return;
        if (i<=L && R<=j)
            ST[root].add=addv(ST[root].add,val);
        else {
            PushDown(root);
            int mid=(L+R)/2;
            if (i<=mid) addRange(2*root+1,L,mid,i,j,val);
            if (j>mid) addRange(2*root+2,mid+1,R,i,j,val);
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
            if (i<=mid) mulRange(2*root+1,L,mid,i,j, val);
            if (j>mid) mulRange(2*root+2,mid+1,R,i,j,val);
        }
    }

    int Query(int i) {                      //查询
        int id=QueryOne(0,0,MAXN-1,i);          //找到累积，累和的索引
        return addv(mulv(a[i],ST[id].mul),ST[id].add); //原数*累积+累和
    }

    int QueryOne(int root,int L,int R,int i) {  //单点查询
        if (L==R) return root;
        else {
            PushDown(root);
            int mid=(L+R)/2;
            if (i<=mid) return QueryOne(2*root+1,L,mid,i);
            else return QueryOne(2*root+2,mid+1,R,i);
        }
    }
public:
    Fancy() {
        ST=vector<SNode>(4*MAXN);
    }
    
    void append(int val) {
        a.push_back(val);
    }
    
    void addAll(int inc) {
        addRange(0,0,MAXN-1,0,a.size()-1,inc);
    }
    
    void multAll(int m) {
        mulRange(0,0,MAXN-1,0,a.size()-1,m);
    }
    
    int getIndex(int idx) {
        if (idx>=a.size()) return -1;
        return Query(idx);
    }
};
