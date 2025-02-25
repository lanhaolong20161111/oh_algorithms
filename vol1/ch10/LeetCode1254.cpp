class Solution {
    int m,n;
    vector<vector<int>> grid;
    int ans;                    //��ŷ�յ��������
    vector<int> parent;         //���鼯�洢�ṹ
    vector<int> rnk;            //��������(��߶ȳ�����)
    vector<bool> onedge;		//�Ƿ��б߽�����
public:
    int closedIsland(vector<vector<int>>& grid) {
        m=grid.size(); n=grid[0].size();
        if(m==1 && n==1) return 0;
        this->grid=grid;
        ans=0;
        Init();
        for(int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                if(grid[i][j]==0) {
                    if(j<n-1 && grid[i][j+1]==0)        //grid[i][j+1]Ϊ1
                        Union(pno(i,j),pno(i,j+1));     //(i,j)��(i,j+1)�ϲ�
                    if(i<m-1 && grid[i+1][j]==0)        //grid[i+1][j]Ϊ1
                        Union(pno(i,j),pno(i+1,j));     //(i+1,j)��(i,j)�ϲ�
                }
            }
        }
        return ans;
    }
    int pno(int i,int j) {       //��άת��Ϊһά
        return i*n+j;
    }
    void initEdge(int x) {
        parent[x]=0;
        onedge[x]=true;
       	ans--;
    }
    void Init() {                              //���鼯��ʼ��
        parent=vector<int>(m*n,0);
        rnk=vector<int>(m*n,0);
        onedge=vector<bool>(m*n,false);
        for (int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j]==0) {
                    int k=pno(i,j);
                    parent[k]=k;
                    rnk[k]=0;
                    ans++;
                }
            }
        }
        for (int i=0;i<m;i++) {
            if(grid[i][0]==0) {         //��0��
                initEdge(pno(i,0));
            }
            if(grid[i][n-1]==0) {       //��n-1��
                initEdge(pno(i,n-1));
            }
        }
        for (int j=1;j<n-1;j++) {
            if(grid[0][j]==0) {         //��0��
                initEdge(pno(0,j));
            }
            if(grid[m-1][j]==0) {       //��m-1��
                initEdge(pno(m-1,j));
            }
        }
    }
    int Find(int x) {                           //�ݹ��㷨�����鼯�в���x���ĸ����
        if (x!=parent[x])
            parent[x]=Find(parent[x]);          //·��ѹ��
        return parent[x];
    }
    void Union(int x,int y) {                   //���鼯��x��y���������ϵĺϲ�
        int rx=Find(x);
        int ry=Find(y);
        if (rx==ry) return;                           //x��y����ͬһ���������
        if (rnk[rx]<rnk[ry]) { 
            parent[rx]=ry;                              //rx�����Ϊry�ĺ���
            onedge[ry]=onedge[ry] | onedge[rx];
        }
        else {
            if (rnk[rx]==rnk[ry]) rnk[rx]++;      //����ͬ���ϲ���rx������1
            parent[ry]=rx;                      //ry�����Ϊrx�ĺ���
            onedge[rx]=onedge[rx] | onedge[ry];
        }
        ans--;
    }
};

