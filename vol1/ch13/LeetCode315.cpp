#define lowbit(x) ((x)&-(x))
class BIT {                     //树状数组类
private:
    vector<int> tree;           //树状数组为tree[1..n]
    int n;
public:
    BIT(int n):n(n),tree(n+1,0) {}
    void UpdateOne(int i,int x) {     //单点修改
        while (i<=n) {
            tree[i]+=x;
            i+=lowbit(i);
        }
    }
    int Sum(int i) {
        int ans=0;
        while (i>0) {
            ans+=tree[i];
            i-=lowbit(i);
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
       int n=nums.size();
        unordered_map<int,int> hmap;        //离散化
        set<int> tset;
        for (int x:nums) tset.insert(x);
        int idx=1;									//序号从1开始
        for(int x:tset) hmap[x]=idx++;
        BIT bit(idx);
        vector<int> ans(n,0);						//存放答案
        for (int j=n-1;j>=0;j--) {
            int i=hmap[nums[j]];
            bit.UpdateOne(i,1);
            if (i!=1) ans[j]=bit.Sum(i-1);
            else ans[j]=0;
        }
        return ans;
    }
};

