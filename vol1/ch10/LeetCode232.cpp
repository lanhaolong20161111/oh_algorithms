class Solution {
    vector<int> parent;         //���鼯�洢�ṹ
    vector<int> rnk;            //��������(��߶ȳ�����)
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        Init(n);
        for(int i=0;i<edges.size();i++) {
            int a=edges[i][0];
            int b=edges[i][1];
            Union(a,b);
        }
        int cnt=0;              //����������
        for(int i=0;i<n;i++) {
            if(parent[i]==i) cnt++;
        }
        return cnt;
    }
    void Init(int n) {                              //���鼯��ʼ��
        parent=vector<int>(n);
        rnk=vector<int>(n);
        for (int i=0;i<n;i++) {
            parent[i]=i;
            rnk[i]=0;
        }
    }
    int Find(int x) {                               //�ݹ��㷨�����鼯�в���x���ĸ����
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

