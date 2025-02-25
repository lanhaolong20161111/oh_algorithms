#define lowbit(x) ((x)&-(x))
class BIT {
    vector<int> tree;                       //树状数组为tree[1..n]
    int n;
public:
    BIT() {}
    void Create(vector<int> &a) {		//由a[0..n-1]创建树状数组
        n=a.size();
        tree.resize(n+1);
        for (int i=1;i<=n;i++) {
            tree[i]+=a[i-1];
            if (i+lowbit(i)<=n)
                tree[i+lowbit(i)]+=tree[i]; 
        }
    }
    void UpdateOne(int i,int x) {           //单点修改
        while (i<=n) {
            tree[i]+=x;
            i+=lowbit(i);
        }
    }    
    int Sum(int i) {                        //求前缀和
        int ans=0;
        while (i) {
            ans+=tree[i];
            i-=lowbit(i);
        }
        return ans;
    }
};
class NumMatrix {
public:
    BIT bit;
    int m,n;
    vector<vector<int>> mat;
    NumMatrix(vector<vector<int>>& matrix) {
        m=matrix.size();
        n=matrix[0].size();
        vector<int> a;
        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                a.emplace_back(matrix[i][j]);
            }
        }
        bit.Create(a);
        mat=matrix;
    }
    int pno(int i,int j) {                              //二维转换为一维
        return i*n+j+1;
    }
    void update(int r, int c, int val) {
        int i=pno(r,c); 
        bit.UpdateOne(i,val-mat[r][c]);
        mat[r][c]=val;
    }
    int sumRegion(int r1,int c1,int r2,int c2) {
        int ans=0;
        for (int r=r1;r<=r2;r++) {
            int i=pno(r,c1);
            int j=pno(r,c2);
            ans+=bit.Sum(j)-bit.Sum(i-1);
        }
        return ans;
    }
};

