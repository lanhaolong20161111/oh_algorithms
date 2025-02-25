class Solution {
    vector<int> parent;         //并查集存储结构
    vector<int> rnk;            //子树的秩(与高度成正比)
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        Init(n);
        for(int i=0;i<edges.size();i++) {
            int a=edges[i][0];
            int b=edges[i][1];
            Union(a,b);
        }
        int cnt=0;              //求子树个数
        for(int i=0;i<n;i++) {
            if(parent[i]==i) cnt++;
        }
        return cnt;
    }
    void Init(int n) {                              //并查集初始化
        parent=vector<int>(n);
        rnk=vector<int>(n);
        for (int i=0;i<n;i++) {
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
            parent[rx]=ry;                 //rx结点作为ry的孩子
        else {
            if (rnk[rx]==rnk[ry]) rnk[rx]++;      //秩相同，合并后rx的秩增1
            parent[ry]=rx;                      //ry结点作为rx的孩子
        }
    }
};

