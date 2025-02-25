class SegTree {             //线段树类
public: 
    vector<int> ST;
    vector<int> a;
    int n;
    SegTree() {}
    SegTree(vector<int> &a) {
        n=a.size();
        this->a=a;
        ST.resize(4*n);
        Create(1,1,n);
    }
    void Create(int root,int L,int R) {
        if (L==R)
            ST[root]=a[L-1];
        else {
            int mid=(L+R)>>1;
            Create(2*root,L,mid);
            Create(2*root+1,mid+1,R);
            ST[root]=ST[2*root]+ST[2*root+1];
        }
    }
    void UpdateOne(int root,int L,int R,int i,int x) {          //单点修改:a[i]+=x
        if(L==R) ST[root]=x;                                            //单点: 直接修改
        else {                                          //非单点
            int mid=(L+R)>>1;
            if(i<=mid) UpdateOne(2*root,L,mid,i,x);		//在左子树中修改
            else UpdateOne(2*root+1,mid+1,R,i,x);   //在右子树中修改
            ST[root]=ST[2*root]+ST[2*root+1];       //向上更新分支结点值
        }
    }
    int QueryRange(int root,int L,int R,int i,int j) {          //查询区间[i,j]
        if(L>=i && R<=j) return ST[root];                              //当前结点[L,R]包含在[i,j]中
        else {
            int mid=(L+R)>>1;                           //其他情况
            int lsum=0,rsum=0;
            if(i<=mid) lsum=QueryRange(2*root,L,mid,i,j);     	 	//递归查询左子树
            if(mid<j) rsum=QueryRange(2*root+1,mid+1,R,i,j); 	//递归查询右子树
            return lsum+rsum;
        }
    }
};
class NumMatrix {
public:
    int m,n;
    SegTree st;
    NumMatrix(vector<vector<int>>& matrix) {
        m=matrix.size(),n=matrix[0].size();
        vector<int> a;
        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                a.emplace_back(matrix[i][j]);
            }
        }
        st=SegTree(a);
    }
    int pno(int i,int j) {      //二维转换为一维
        return i*n+j+1;
    }
    void update(int r,int c,int val) {
        int i=pno(r,c);
        st.UpdateOne(1,1,m*n,i,val);
    }
    int sumRegion(int r1,int c1,int r2,int c2) {
        int ans=0;
        for (int i=r1;i<=r2;i++) {
            ans+=st.QueryRange(1,1,m*n,pno(i,c1),pno(i,c2));
        }
        return ans;
    }
};

