class Solution {
    vector<int> parent;         //���鼯�洢�ṹ
    vector<int> rnk;            //��������(��߶ȳ�����)
public:
    vector<int> findRedundantConnection(vector<vector<int>>&edges) {
        int n=edges.size();                                 //nΪ�������
        Init(n);                                //���鼯��ʼ��
        for (int i=0;i<n;i++) {
            vector<int> tmp=edges[i];           //ȡһ����tmp
            int x=tmp[0],y=tmp[1];                  //ȡһ���ߵ�ͷβ����
            int rx=Find(x);
            int ry=Find(y);                     //�ֱ�õ���������������ͨ�������
            if (rx!=ry)                             //���������ڲ�ͬ�ļ���
                parent[rx]=ry;                  //���������ϲ����¸�Ϊry
            else                                //˵���л�
                return tmp;                 //���������tmp
        }
        return {};
    }
    void Init(int n) {                              //���鼯��ʼ��
        parent=vector<int>(n+1);
        rnk=vector<int>(n+1);
        for (int i=1;i<=n;i++) {
            parent[i]=i;
            rnk[i]=0;
        }
    }
    int Find(int x) {                               //�ݹ��㷨�����鼯�в���x���ĸ����
        if (x!=parent[x])
            parent[x]=Find(parent[x]);          //·��ѹ��
        return parent[x];
    }
};

