class Solution {
    vector<int> parent;         //���鼯�洢�ṹ
    vector<int> rnk;            //��������(��߶ȳ�����)    
    int m,n;
public:
    bool containsCycle(vector<vector<char>>& grid) {
        m=grid.size();
        n=grid[0].size();
        Init(m*n);
        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                int curv=grid[i][j];
                if(j<n-1 && grid[i][j+1]==curv) {       //grid[i][j+1]Ϊcurv
                    if(Union(pno(i,j),pno(i,j+1)))
                        return true;
                }
                if(i<m-1 && grid[i+1][j]==curv) {        //grid[i+1][j]Ϊcurv
                    if(Union(pno(i,j),pno(i+1,j)))
                        return true;                    //(i+1,j)��(i,j)�ϲ�
                }
            }
        }
        return false;
    }

    int pno(int i,int j) {       //��άת��Ϊһά
        return i*n+j;
    }

    void Init(int n) {              //���鼯��ʼ��
        parent=vector<int>(n,0);
        rnk=vector<int>(n,0);
        for(int i=0;i<n;i++) {
            parent[i]=i;
            rnk[i]=0;
        }
    }
    int Find(int x) {                       //�ݹ��㷨�����鼯�в���x���ĸ����
        if (x!=parent[x])
            parent[x]=Find(parent[x]);      //·��ѹ��
        return parent[x];
    }

    bool Union(int x,int y) {                       //���鼯��x��y���������ϵĺϲ�
        int rx=Find(x);
        int ry=Find(y);
        if (rx==ry) return true;                           //x��y����ͬһ���������
        if (rnk[rx]<rnk[ry])
            parent[rx]=ry;                              //rx�����Ϊry�ĺ���
        else {
            if (rnk[rx]==rnk[ry]) rnk[rx]++;      //����ͬ���ϲ���rx������1
            parent[ry]=rx;                      //ry�����Ϊrx�ĺ���
        }
        return false;
    }
};

