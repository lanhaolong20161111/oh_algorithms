#define lowbit(x) ((x)&-(x))
class BIT {
    vector<int> tree;                       //树状数组为tree[1..n]
    int n;
public:
    BIT(int n):n(n),tree(n+1,0) {}
    void UpdateOne(int i,int x) {           //单点修改
        while (i<=n) {
            tree[i]+=x;
            i+=lowbit(i);
        }
    }
    int Sum(int i) {                        //求前缀和
        int ans=0;
        while (i>0) {
            ans+=tree[i];
            i-=lowbit(i);
        }
        return ans;
    }
};
class Solution {
    static const int MOD=1000000007;
public:
    int createSortedArray(vector<int>& instructions) {
        int maxv=*max_element(instructions.begin(),instructions.end());
        BIT bit(maxv);
        long long ans=0;
        for (int j=0;j<instructions.size();j++) {
            int i=instructions[j];
            int smaller=bit.Sum(i-1);
            int larger=j-bit.Sum(i);
            ans+=min(smaller, larger);
            bit.UpdateOne(i,1);
        }
        return ans % MOD;
    }
};

