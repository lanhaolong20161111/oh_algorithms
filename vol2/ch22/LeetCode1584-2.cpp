struct Edge {                                       //����
  int u,v,w;                                  //�ߵ����, �յ��Ȩֵ
  Edge(int u1,int v1,int w1):u(u1),v(v1),w(w1) {}   //���캯��
  bool operator<(const Edge &e) const {
    return w<e.w;                   //���ڰ�w��������
  }
};
class UFS {         //���鼯��
  int n;
  vector<int> parent;                   //���鼯�洢�ṹ
  vector<int> rnk;                      //�洢������(�����ڸ߶�)
public:
  UFS(int n) {
    this->n=n;
    parent=vector<int>(n);
    rnk=vector<int>(n);
  }
  void Init() {                     //���鼯��ʼ��
    for (int i=0;i<n;i++) {
      parent[i]=i;
      rnk[i]=0;
    }
  }
  int Find(int x) {                   //�ݹ��㷨������x���ĸ����
      if (x!=parent[x])
        parent[x]=Find(parent[x]);    //·��ѹ��
      return parent[x];
  }
  void Union(int rx,int ry) {         //���鼯��rx��ry���������ϵĺϲ�
    if (rnk[rx]<rnk[ry])
      parent[rx]=ry;                  //rx�����Ϊry�ĺ���
    else {
      if (rnk[rx]==rnk[ry])         //����ͬ���ϲ���rx������1
        rnk[rx]++;
      parent[ry]=rx;            //ry�����Ϊrx�ĺ���
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
  int dist(vector<vector<int>>& points,int i,int j) { //�������پ���
    return abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
  }
  int Kruskal(vector<vector<int>>&points) {           //Kruskal�㷨
    int n=points.size();
    UFS ufs(n);
    int ans=0;;          //�����С�������ĳ���
    vector<Edge> E;
    for(int i=0;i<n;i++)   {            //��A�����ǲ��ֲ����ı߼�E
      for(int j=0;j<i;j++) {
          E.push_back(Edge(i,j,dist(points,i,j)));
      }
    }
    sort(E.begin(),E.end());
    ufs.Init();                     //��ʼ�����鼯
    int k=0;                         //kΪ��ǰ�����������ı���
    int j=0;                          //E�бߵ��±�,��ֵΪ0
    while (k<n-1) {                   //���ɵı���С��n-1ʱѭ��
      int u1=E[j].u;
      int v1=E[j].v;                  //ȡһ���ߵ�ͷβ����u1��v2
      int sn1=ufs.Find(u1);
      int sn2=ufs.Find(v1);           //�ֱ�õ�����������Ӽ������
      if (sn1!=sn2) {                 //��Ӹñ߲��ṹ�ɻ�·
        ans+=E[j].w;                  //������С��������һ����
        k++;                          //���ɱ�����1
        ufs.Union(sn1,sn2);           //��sn1��sn2��������ϲ�
      }
      j++;                            //������һ����
    }
    return ans;
  }
};

