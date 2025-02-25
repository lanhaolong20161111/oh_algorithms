class SegTree {             //�߶�����
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
    void UpdateOne(int root,int L,int R,int i,int x) {          //�����޸�:a[i]+=x
        if(L==R) ST[root]=x;                                            //����: ֱ���޸�
        else {                                          //�ǵ���
            int mid=(L+R)>>1;
            if(i<=mid) UpdateOne(2*root,L,mid,i,x);		//�����������޸�
            else UpdateOne(2*root+1,mid+1,R,i,x);   //�����������޸�
            ST[root]=ST[2*root]+ST[2*root+1];       //���ϸ��·�֧���ֵ
        }
    }
    int QueryRange(int root,int L,int R,int i,int j) {          //��ѯ����[i,j]
        if(L>=i && R<=j) return ST[root];                              //��ǰ���[L,R]������[i,j]��
        else {
            int mid=(L+R)>>1;                           //�������
            int lsum=0,rsum=0;
            if(i<=mid) lsum=QueryRange(2*root,L,mid,i,j);     	 	//�ݹ��ѯ������
            if(mid<j) rsum=QueryRange(2*root+1,mid+1,R,i,j); 	//�ݹ��ѯ������
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
    int pno(int i,int j) {      //��άת��Ϊһά
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

