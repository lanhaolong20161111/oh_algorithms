typedef long long LL;
const int MAXN=4e6+10;
struct SNode {								//�߶����������
    int val;
    int left,right;
    SNode():val(0),left(0),right(0) {}
};
class Solution {
public:
    int idx=0,root=0;
    SNode ST[MAXN];							//����߶���
    void UpdateOne(int &root, LL L, LL R, LL i) {
        if (root==0) root=++idx;				//��̬����
        if (L==R && L==i) ST[root].val+=1;
        else {
            LL mid=(L+R)>>1;
            if (i<=mid) UpdateOne(ST[root].left,L,mid,i);
            else UpdateOne(ST[root].right,mid+1,R,i);
            ST[root].val=ST[ST[root].left].val+ST[ST[root].right].val;
        }
    }
    LL QueryRange(int root, LL L, LL R, LL i, LL j) {
        if (i<=L && j>=R) return ST[root].val;
        else {
            LL mid=(L+R)>>1;
            LL ans=0;
            if (i<=mid) ans+=QueryRange(ST[root].left,L,mid,i,j);
            if (j>mid) ans+=QueryRange(ST[root].right,mid+1,R,i,j);
            return ans;
        }
    }
    int countRangeSum(vector<int>& nums,int lower,int upper) {
        int n=nums.size();
        vector<LL> presum(n+1);         //ǰ׺������
        presum[0]=0;
        for(int i=1;i<=n;i++)
            presum[i]=presum[i-1]+nums[i-1];
        LL minv=LLONG_MAX,maxv=LLONG_MIN;
        for(LL x: presum) {							//���������[minv,maxv]
            minv=min({minv,x,x-upper});
            maxv=max({maxv,x,x-lower});
        }
        LL ans=0;
        for(LL x: presum) {
            LL i=x-upper,j=x-lower;
            ans+=QueryRange(1,minv,maxv,i,j);					//�߶����ĸ����ΪST[1]
            UpdateOne(root,minv,maxv,x);
        }
        return ans;
    }
};

