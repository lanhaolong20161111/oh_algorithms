class Solution {
    vector<int> parent;         //���鼯�洢�ṹ
    vector<int> rnk;            //��������(��߶ȳ�����)
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        Init(n);
        for(int i=0;i<n;i++){
            if(graph[i].size()==0) continue;
            int u=graph[i][0];
            for(int j=1;j<graph[i].size();j++) {
			int v= graph[i][j];
                Union(u,v);
            }
        }
        for(int i=0;i<n;i++) {
            for(int j=0;j<graph[i].size();j++) {
                if(Find(i)==Find(graph[i][j])) return false;
            }
        }
        return true;
    }
    void Init(int n) {                              //���鼯��ʼ��
        parent=vector<int>(n);
        rnk=vector<int>(n);
        for (int i=0;i<n;i++) {
            parent[i]=i;
            rnk[i]=0;
        }
    }
    int Find(int x) {                             //�ݹ��㷨�����鼯�в���x���ĸ����
        if (x!=parent[x])
            parent[x]=Find(parent[x]);          //·��ѹ��
        return parent[x];
    }
    void Union(int x,int y) {                       //���鼯��x��y���������ϵĺϲ�
        int rx=Find(x);
        int ry=Find(y);
        if (rx==ry) return;                           //x��y����ͬһ���������
        if (rnk[rx]<rnk[ry])
            parent[rx]=ry;                 //rx�����Ϊry�ĺ���
        else {
            if (rnk[rx]==rnk[ry]) rnk[rx]++;      //����ͬ���ϲ���rx������1
            parent[ry]=rx;                      //ry�����Ϊrx�ĺ���
        }
    }
};

