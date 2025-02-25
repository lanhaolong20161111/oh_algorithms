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
public:
    vector<int> processQueries(vector<int>& queries,int m) {
        int n=queries.size();
        BIT bit(m+n);
        vector<int> pos(m+1);
        for (int i=1;i<=m;i++) {
            pos[i]=n+i;         				//1～m的数到位置的映射
            bit.UpdateOne(n+i,1);		//在树状数组中添加1～m的数
        }
        vector<int> ans;
        for (int j=0;j<n;j++) {
            int i=pos[queries[j]];			//求queries[j]在pos中的索引
            ans.push_back(bit.Sum(i)-1);		//求queries[j]在P中的的位置
            bit.UpdateOne(i,-1);    //把位置i的数移动到最前面
            pos[queries[j]]=n-j;
            bit.UpdateOne(n-j,1);
        }
        return ans;
    }
};

