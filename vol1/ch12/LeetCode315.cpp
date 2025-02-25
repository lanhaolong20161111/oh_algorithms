class SegmentTree{				//线段树类
    vector<int> ST;             //存放线段树
public:
    SegmentTree(int n) {
        ST=vector<int>(4*nh,0);
    }
    int QueryRange(int root,int L,int R,int i,int j) {
        if (L>=i && R<=j)
            return ST[root];
        else {
            int mid=(L+R)/2;
            int lsum=0,rsum=0;
            if (i<=mid) lsum=QueryRange(2*root+1,L,mid,i,j);
            if (j>mid) rsum=QueryRange(2*root+2,mid+1,R,i,j);
            return lsum+rsum;
        }
    }
    void UpdateOne(int root,int L,int R,int i,int x) {
        if (L==R) ST[root]+=x;
        else {
            int mid=(L+R)/2;
            if (i<=mid) UpdateOne(2*root+1,L,mid,i,x);
            else UpdateOne(2*root+2,mid+1,R,i,x);
            ST[root]=ST[2*root+1]+ST[2*root+2];
        }
    }
};
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> hmap;            //离散化
        set<int> tset;
        for (int x:nums) tset.insert(x);
        int idx=0;
        for(int x:tset) hmap[x]=idx++;
        SegmentTree st(n);
        vector<int> ans;
        for (int i=n-1;i>=0;i--) {
            int x=nums[i];
            int id=hmap[x];
            if (id>0) {
                int sum=st.QueryRange(0, 0, n-1,0,id-1);
                ans.push_back(sum);
            }
            else ans.push_back(0);
            st.UpdateOne(0,0,n-1,id,1);
        }
        reverse(ans.begin(),ans.end());
        return ans;
     }
};

