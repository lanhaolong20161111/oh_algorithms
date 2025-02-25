const int MAXN=100005;
const int MOD=1000000007;
struct SNode {							//�߶����������
    int val;        //ԭ��
    int add;        //����add��
    int mul;        //����mul��
    int left,right;
    SNode():add(0),mul(1),left(-1),right(-1) {}
};
class Fancy {
    vector<SNode> ST;
    int end;                        //���Ԫ�ص�λ�ã���ӵ�Ԫ�ظ�����
    int addv(int a,int b) {			//��ģ����
        return (int) ((1l*a+1l*b) % MOD);
    }

    void PushDown(int root) {           //���´����㷨
        if(ST[root].left==-1) {        //��̬����:��������
            ST.push_back(SNode());
            ST[root].left=ST.size()-1;
        }
        if(ST[root].right==-1) {        //��̬����:�����Һ���
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

    void addRange(int root,int L,int R,int i,int j,int val) {   //����ӷ��޸�
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
            if (i<=mid) mulRange(ST[root].left,L,mid,i,j, val);
            if (j>mid) mulRange(ST[root].right,mid+1,R,i,j,val);
        }
    }

    int Query(int i) {                      //��ѯ
        int id=QueryOne(0,0,MAXN-1,i);          //�ҵ��ۻ����ۺ͵�����
        return addv(mulv(ST[i].val,ST[id].mul),ST[id].add); //ԭ��*�ۻ�+�ۺ�
    }

    int QueryOne(int root,int L,int R,int i) {  //�����ѯ
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
        ST.push_back(SNode());       //���߶�������Ӹ����ST[0]
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
