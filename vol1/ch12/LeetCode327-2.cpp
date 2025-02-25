typedef long long LL;
class Solution {
    vector<int> ST;
public:
    void UpdateOne(int root,LL L,LL R,LL i) {
        if (L==R)
            ST[root]+=1;
        else {
            LL mid=(L+R)>>1;
            if (i<=mid)
                UpdateOne(2*root+1,L,mid,i);
            else
                UpdateOne(2*root+2,mid+1,R,i);
            ST[root]=ST[2*root+1]+ST[2*root+2];
        }
    }
    LL QueryRange(int root, LL L, LL R, LL i, LL j) {
        if (i<=L && j>=R)
            return ST[root];
        else {
            LL mid=(L+R)>>1;
            LL ans=0;
            if (i<=mid) ans+=QueryRange(2*root+1,L,mid,i,j);
            if (j>mid) ans+=QueryRange(2*root+2,mid+1,R,i,j);
            return ans;
        }
    }
    int countRangeSum(vector<int>& nums,int lower,int upper) {
        int n=nums.size();
        vector<LL> presum(n+1);         //前缀和数组
        presum[0]=0;
        for(int i=1;i<=n;i++)
            presum[i]=presum[i-1]+nums[i-1];
        set<LL> tset;                   //除重
        for (LL x:presum) {
            tset.insert(x);
            tset.insert(x-lower);
            tset.insert(x-upper);
        }
        unordered_map<LL,int> hmap;     //离散化
        int idx=0;
        for(LL x:tset) {
            hmap[x]=idx++;
        }
        ST=vector<int>(6*idx,0);
        int ans=0;
        for(LL x: presum) {
            int i=hmap[x-upper],j=hmap[x-lower];
            ans+=QueryRange(0,0,idx-1,i,j);
            int k=hmap[x];
            UpdateOne(0,0,idx-1,k);
        }
        return ans;
    }
};

