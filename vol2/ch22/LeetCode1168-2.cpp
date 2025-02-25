bool cmp(const vector<int>&s,const vector<int>&t) {		//用于按边权递增排序
        return s[2]<t[2];
}
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
    int minCostToSupplyWater(int n,vector<int>&wells,vector<vector<int>>&pipes) {
		if(n==1) return wells[n-1];
        for(int i=1;i<=n;i++)       //建立超级源点0
            pipes.push_back({0,i,wells[i-1]});
        return Kruskal(n+1,pipes);
    }
    int Kruskal(int n,vector<vector<int>>&E) {      //Kruskal算法
        UFS ufs(n);
        int ans=0;;          //存放最小生成树的长度
        sort(E.begin(),E.end(),cmp);
        ufs.Init();                     //初始化并查集
        int k=0;                         //k为当前构造生成树的边数
        int j=0;                          //E中边的下标,初值为0
        while (k<n-1) {                   //生成的边数小于n-1时循环
            int u1=E[j][0];
            int v1=E[j][1];                  //取一条边的头尾顶点u1和v2
            int sn1=ufs.Find(u1);
            int sn2=ufs.Find(v1);           //分别得到两个顶点的子集树编号
            if (sn1!=sn2) {                 //添加该边不会构成回路
                ans+=E[j][2];                  //生成最小生成树的一条边
               k++;                          //生成边数增1
                ufs.Union(sn1,sn2);           //将sn1和sn2两个顶点合并
            }
            j++;                            //遍历下一条边
        }
        return ans;
    }
};

