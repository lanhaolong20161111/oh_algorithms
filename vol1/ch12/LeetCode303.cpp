class NumArray {
private:
    static const int MAXN=10010;
    int ST[4*MAXN];                             //存放线段树中结点的a值
    vector<int> a;
    void Create(int root,int L,int R) {     //创建线段树
        if(L==R)                                //叶子结点
            ST[root]=a[L];
        else {
            int mid=(L+R)/2;
            Create(2*root+1,L,mid);             //递归构造左子树
            Create(2*root+2,mid+1,R);               //递归构造右子树
            ST[root]=ST[2*root+1]+ST[2*root+2];     //向上更新
        }
    }
    int QueryRange(int root,int L,int R,int i,int j) {   //区间查询
        if(L>=i && R<=j)                        //当前结点区间[L,R]包含在[i,j]中
            return ST[root];
        else {
            int mid=(L+R)/2;                        //其他情况 
            int sum=0;
            if(i<=mid)                          //若[i,j]与左孩子有交集
                sum+=QueryRange(2*root+1,L,mid,i,j);
            if(j>=mid+1)                        //若[i,j]与右孩子有交集
                sum+=QueryRange(2*root+2,mid+1,R,i,j);
            return sum;
        }
    }
public:
    NumArray(vector<int>& nums) {
        a=nums;
        int n=nums.size();
        Create(0,0,n-1);
    }
    int sumRange(int i,int j) {
        int n=a.size();
        return QueryRange(0,0,n-1,i,j);
    }
};

