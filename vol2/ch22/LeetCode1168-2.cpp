bool cmp(const vector<int>&s,const vector<int>&t) {		//���ڰ���Ȩ��������
        return s[2]<t[2];
}
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
    int minCostToSupplyWater(int n,vector<int>&wells,vector<vector<int>>&pipes) {
		if(n==1) return wells[n-1];
        for(int i=1;i<=n;i++)       //��������Դ��0
            pipes.push_back({0,i,wells[i-1]});
        return Kruskal(n+1,pipes);
    }
    int Kruskal(int n,vector<vector<int>>&E) {      //Kruskal�㷨
        UFS ufs(n);
        int ans=0;;          //�����С�������ĳ���
        sort(E.begin(),E.end(),cmp);
        ufs.Init();                     //��ʼ�����鼯
        int k=0;                         //kΪ��ǰ�����������ı���
        int j=0;                          //E�бߵ��±�,��ֵΪ0
        while (k<n-1) {                   //���ɵı���С��n-1ʱѭ��
            int u1=E[j][0];
            int v1=E[j][1];                  //ȡһ���ߵ�ͷβ����u1��v2
            int sn1=ufs.Find(u1);
            int sn2=ufs.Find(v1);           //�ֱ�õ�����������Ӽ������
            if (sn1!=sn2) {                 //��Ӹñ߲��ṹ�ɻ�·
                ans+=E[j][2];                  //������С��������һ����
               k++;                          //���ɱ�����1
                ufs.Union(sn1,sn2);           //��sn1��sn2��������ϲ�
            }
            j++;                            //������һ����
        }
        return ans;
    }
};

