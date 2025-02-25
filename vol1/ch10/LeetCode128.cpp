class Solution {
    const int FLAG=0x3f3f3f3f;
    unordered_map<int,int> parent;    //记录每个结点的父结点
    unordered_map<int,int> cnt;         //子树中的整数个数
public:
    int longestConsecutive(vector<int>& nums) {
        Init(nums);
        int n=nums.size();
        for (int i=0;i<n;i++) {
            if (Find(nums[i]+1)!=FLAG)  //当存在nums[i]+1
                Union(nums[i],nums[i]+1);   //将其合并
        }
        int ans=0;
        for (int i=0;i<n;i++) {         //求最多的子树结点个数
            ans=max(ans,cnt[nums[i]]);
        }
        return ans;
    }
    void Init(vector<int>& nums) {              //并查集初始化
        for (int i=0;i<nums.size();i++) {
            parent[nums[i]]=nums[i];
            cnt[nums[i]]=1;
        }
    }
    int Find(int x) {                          //递归算法：并查集中查找x结点的根结点
        if(parent.count(x)==0)  //nums不包含x
            return FLAG;
        if (x!=parent[x])
            parent[x]=Find(parent[x]);          //路径压缩
        return parent[x];
    }
    void Union(int x,int y) {                     //并查集中x和y的两个集合的合并
        int rx=Find(x);
        int ry=Find(y);
        if (rx==ry) return;                       //x和y属于同一棵树的情况
        parent[rx]=ry;
        cnt[ry]+=cnt[rx];
    }
};

