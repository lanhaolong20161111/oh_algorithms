class Solution {
    int m,n;
    vector<vector<int>> grid;
    int ans;
    vector<int> parent;         //���鼯�洢�ṹ
    vector<int> rnk;            //��������(��߶ȳ�����)
    vector<int> cnt;            //�����е�������
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m=grid.size(); n=grid[0].size();
        this->grid=grid;
        ans=0;
        Init();
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j]==1) {
                    if(j<n-1 && grid[i][j+1]==1)        //grid[i][j+1]Ϊ1
                        Union(pno(i,j),pno(i,j+1));     //(i,j)��(i,j+1)�ϲ�
                    if(i<m-1 && grid[i+1][j]==1)        //grid[i+1][j]Ϊ1
                        Union(pno(i,j),pno(i+1,j));     //(i+1,j)��(i,j)�ϲ�
                }
            }
        }
        return ans;
    }
    int pno(int i,int j) {       //��άת��Ϊһά
        return i*n+j;
    }
    void Init() {                              //���鼯��ʼ��
        parent=vector<int>(m*n,0);
        rnk=vector<int>(m*n,0);
        cnt=vector<int>(m*n,0);
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j]==1) {
                    int k=pno(i,j);
                    parent[k]=k;
                    rnk[k]=0;
                    cnt[k]=1;
                    ans=1;                  //ֻ��������,ans����Ϊ1
                }
            }
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
        if (rnk[rx]<rnk[ry]) {
            parent[rx]=ry;                              //rx�����Ϊry�ĺ���
            cnt[ry]+=cnt[rx];
            ans=max(ans,cnt[ry]);
        }
        else {
            if (rnk[rx]==rnk[ry]) rnk[rx]++;      //����ͬ���ϲ���rx������1
            parent[ry]=rx;                      //ry�����Ϊrx�ĺ���
            cnt[rx]+=cnt[ry];
            ans=max(ans,cnt[rx]);
        }
    }
};

