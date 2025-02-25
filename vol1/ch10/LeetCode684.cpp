class Solution {
    vector<int> parent;         //并查集存储结构
    vector<int> rnk;            //子树的秩(与高度成正比)
public:
    vector<int> findRedundantConnection(vector<vector<int>>&edges) {
        int n=edges.size();                                 //n为顶点个数
        Init(n);                                //并查集初始化
        for (int i=0;i<n;i++) {
            vector<int> tmp=edges[i];           //取一条边tmp
            int x=tmp[0],y=tmp[1];                  //取一条边的头尾顶点
            int rx=Find(x);
            int ry=Find(y);                     //分别得到两个顶点所属连通分量编号
            if (rx!=ry)                             //两顶点属于不同的集合
                parent[rx]=ry;                  //两棵子树合并，新根为ry
            else                                //说明有环
                return tmp;                 //返回冗余边tmp
        }
        return {};
    }
    void Init(int n) {                              //并查集初始化
        parent=vector<int>(n+1);
        rnk=vector<int>(n+1);
        for (int i=1;i<=n;i++) {
            parent[i]=i;
            rnk[i]=0;
        }
    }
    int Find(int x) {                               //递归算法：并查集中查找x结点的根结点
        if (x!=parent[x])
            parent[x]=Find(parent[x]);          //路径压缩
        return parent[x];
    }
};

