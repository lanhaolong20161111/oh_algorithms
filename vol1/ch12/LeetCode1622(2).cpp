const int MAXN=100005;
const int MOD=1000000007;
struct SNode {							//�߶����������
    int val;        //ԭ��
    int add;        //����add��
    int mul;        //����mul��
    SNode():add(0),mul(1) {}
};
class Fancy {
    vector<int> a;							//�����ӵ���������
    vector<SNode> ST;

    int addv(int a,int b) {			//��ģ����
        return (int) ((1l*a+1l*b) % MOD);
    }

    void PushDown(int root) {           //���´����㷨
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

    void addRange(int root,int L,int R,int i,int j,int val) {   //����ӷ��޸�
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
    int mulv(int a,int b) {				//��ģ����
        return (int) (1l*a*b % MOD);
    }

    void mulRange(int root,int L, int R,int i, int j, int val) { //����˷��޸�
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

    int Query(int i) {                      //��ѯ
        int id=QueryOne(0,0,MAXN-1,i);          //�ҵ��ۻ����ۺ͵�����
        return addv(mulv(a[i],ST[id].mul),ST[id].add); //ԭ��*�ۻ�+�ۺ�
    }

    int QueryOne(int root,int L,int R,int i) {  //�����ѯ
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
