class NumArray {
private:
    static const int MAXN=10010;
    int ST[4*MAXN];                             //����߶����н���aֵ
    vector<int> a;
    void Create(int root,int L,int R) {     //�����߶���
        if(L==R)                                //Ҷ�ӽ��
            ST[root]=a[L];
        else {
            int mid=(L+R)/2;
            Create(2*root+1,L,mid);             //�ݹ鹹��������
            Create(2*root+2,mid+1,R);               //�ݹ鹹��������
            ST[root]=ST[2*root+1]+ST[2*root+2];     //���ϸ���
        }
    }
    int QueryRange(int root,int L,int R,int i,int j) {   //�����ѯ
        if(L>=i && R<=j)                        //��ǰ�������[L,R]������[i,j]��
            return ST[root];
        else {
            int mid=(L+R)/2;                        //������� 
            int sum=0;
            if(i<=mid)                          //��[i,j]�������н���
                sum+=QueryRange(2*root+1,L,mid,i,j);
            if(j>=mid+1)                        //��[i,j]���Һ����н���
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

