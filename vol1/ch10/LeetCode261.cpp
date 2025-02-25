class Solution {
    vector<int> parent;         //并查集存储结构
public:
    bool validTree(int n,vector<vector<int>>& edges) {
        Init(n);
        for(int i=0;i<edges.size();i++) {
            int a=edges[i][0];
            int b=edges[i][1];
            if(!Union(a,b)) return false;
        }
        int cnt=0;
        for(int i=0;i<n;i++) {
            if(parent[i]==i) cnt++;
        }
        return cnt==1;
    }
    void Init(int n) {                              //并查集初始化
        parent=vector<int>(n);
        for (int i=0;i<n;i++)
            parent[i]=i;
    }
    int Find(int x) {                               //递归算法：并查集中查找x结点的根结点
        if (x!=parent[x])
            parent[x]=Find(parent[x]);          //路径压缩
        return parent[x];
    }
    bool Union(int x,int y) {                       //并查集中x和y的两个集合的合并
        int rx=Find(x);
        int ry=Find(y);
        if (rx==ry) return false;               //x和y属于同一棵树的情况
        else {
            parent[ry]=rx;                      //ry结点作为rx的孩子
            return true;
        }
    }
};

