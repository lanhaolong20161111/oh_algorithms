class Solution {
    vector<int> parent;         //���鼯�洢��
    vector<int> rnk;            //��������(��߶ȳ�����)
public:
    bool equationsPossible(vector<string>& equations) {
        int n=equations.size();
        Init(26);
        for (int i=0;i<n;i++) {
            if (equations[i][1]=='=') {
                int x=equations[i][0]-'a';
                int y=equations[i][3]-'a';
                Union(x,y);
            }
        }
        for (int i=0;i<n;i++) {
            if (equations[i][1]=='!') {
                int x=equations[i][0]-'a';
                int y=equations[i][3]-'a';
                if (Find(x)==Find(y)) {
                    return false;
                }
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

