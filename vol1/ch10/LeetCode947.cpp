class Solution {
    vector<int> parent;         //���鼯�洢�ṹ
    vector<int> rnk;            //��������(��߶ȳ�����)
    int ans;                    //ͬ�л���ͬ�е�ʯͷ��Ŀ
public:
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        ans=n;
        Init(n);
        for (int i=0;i<n;i++) {
            for (int j=i+1;j<n;j++) {
                if (stones[i][0]==stones[j][0] || stones[i][1]==stones[j][1])
                    Union(i,j);
            }
        }
        return n-ans;
    }
    void Init(int n) {                              //���鼯��ʼ��
        parent=vector<int>(n,0);
        rnk=vector<int>(n,0);
        for(int i=0;i<n;i++) {
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
            parent[rx]=ry;                              //rx�����Ϊry�ĺ���
        else {
            if (rnk[rx]==rnk[ry]) rnk[rx]++;      //����ͬ���ϲ���rx������1
            parent[ry]=rx;                      //ry�����Ϊrx�ĺ���
        }
        ans--;
    }
};

