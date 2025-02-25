
class Solution {
    const int MAXN=10001;
    vector<int> parent;         //并查集存储结构
    vector<int> rnk;            //子树的秩(与高度成正比)
public:
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        Init(2*MAXN);
        for (int i=0;i<n;i++)
            Union(stones[i][0],MAXN+stones[i][1]);
        unordered_set<int> hset;        //行号除重
        for(int i=0;i<n;i++)
            hset.insert(stones[i][0]);
        int ans=0;
        for(int i:hset) {
            if(Find(i)==i) ans++;
        }
        return n-ans;
    }

    void Init(int n) {              //并查集初始化
        parent=vector<int>(n,0);
        rnk=vector<int>(n,0);
        for(int i=0;i<n;i++) {
            parent[i]=i;
            rnk[i]=0;
        }
    }
    int Find(int x) {                               //递归算法：并查集中查找x结点的根结点
        if (x!=parent[x])
            parent[x]=Find(parent[x]);          //路径压缩
        return parent[x];
    }
    void Union(int x,int y) {                       //并查集中x和y的两个集合的合并
        int rx=Find(x);
        int ry=Find(y);
        if (rx==ry) return;                           //x和y属于同一棵树的情况
        if (rnk[rx]<rnk[ry])
            parent[rx]=ry;                              //rx结点作为ry的孩子
        else {
            if (rnk[rx]==rnk[ry]) rnk[rx]++;      //秩相同，合并后rx的秩增1
            parent[ry]=rx;                      //ry结点作为rx的孩子
        }
    }
};

