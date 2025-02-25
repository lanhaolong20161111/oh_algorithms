struct Edge {                                       //边类
  int u,v,w;                                  //边的起点, 终点和权值
  Edge(int u1,int v1,int w1):u(u1),v(v1),w(w1) {}   //构造函数
  bool operator<(const Edge &e) const {
    return w<e.w;                   //用于按w递增排序
  }
};
class UFS {         //并查集类
  int n;
  vector<int> parent;                   //并查集存储结构
  vector<int> rnk;                      //存储结点的秩(近似于高度)
public:
  UFS(int n) {
    this->n=n;
    parent=vector<int>(n);
    rnk=vector<int>(n);
  }
  void Init() {                     //并查集初始化
    for (int i=0;i<n;i++) {
      parent[i]=i;
      rnk[i]=0;
    }
  }
  int Find(int x) {                   //递归算法：查找x结点的根结点
      if (x!=parent[x])
        parent[x]=Find(parent[x]);    //路径压缩
      return parent[x];
  }
  void Union(int rx,int ry) {         //并查集中rx和ry的两个集合的合并
    if (rnk[rx]<rnk[ry])
      parent[rx]=ry;                  //rx结点作为ry的孩子
    else {
      if (rnk[rx]==rnk[ry])         //秩相同，合并后rx的秩增1
        rnk[rx]++;
      parent[ry]=rx;            //ry结点作为rx的孩子
    }
  }
};
class Solution {
  const int INF=0x3f3f3f3f;
public:
  int minCostConnectPoints(vector<vector<int>>& points) {
    int n=points.size();
    if(n==1) return 0;
    if(n==2) return dist(points,0,1);
    return Kruskal(points);
  }
  int dist(vector<vector<int>>& points,int i,int j) { //求曼哈顿距离
    return abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
  }
  int Kruskal(vector<vector<int>>&points) {           //Kruskal算法
    int n=points.size();
    UFS ufs(n);
    int ans=0;;          //存放最小生成树的长度
    vector<Edge> E;
    for(int i=0;i<n;i++)   {            //由A下三角部分产生的边集E
      for(int j=0;j<i;j++) {
          E.push_back(Edge(i,j,dist(points,i,j)));
      }
    }
    sort(E.begin(),E.end());
    ufs.Init();                     //初始化并查集
    int k=0;                         //k为当前构造生成树的边数
    int j=0;                          //E中边的下标,初值为0
    while (k<n-1) {                   //生成的边数小于n-1时循环
      int u1=E[j].u;
      int v1=E[j].v;                  //取一条边的头尾顶点u1和v2
      int sn1=ufs.Find(u1);
      int sn2=ufs.Find(v1);           //分别得到两个顶点的子集树编号
      if (sn1!=sn2) {                 //添加该边不会构成回路
        ans+=E[j].w;                  //生成最小生成树的一条边
        k++;                          //生成边数增1
        ufs.Union(sn1,sn2);           //将sn1和sn2两个顶点合并
      }
      j++;                            //遍历下一条边
    }
    return ans;
  }
};

