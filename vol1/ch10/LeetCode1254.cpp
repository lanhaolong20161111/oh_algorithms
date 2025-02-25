class Solution {
    int m,n;
    vector<vector<int>> grid;
    int ans;                    //存放封闭岛屿的数量
    vector<int> parent;         //并查集存储结构
    vector<int> rnk;            //子树的秩(与高度成正比)
    vector<bool> onedge;		//是否有边界土地
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
                    if(j<n-1 && grid[i][j+1]==0)        //grid[i][j+1]为1
                        Union(pno(i,j),pno(i,j+1));     //(i,j)和(i,j+1)合并
                    if(i<m-1 && grid[i+1][j]==0)        //grid[i+1][j]为1
                        Union(pno(i,j),pno(i+1,j));     //(i+1,j)和(i,j)合并
                }
            }
        }
        return ans;
    }
    int pno(int i,int j) {       //二维转换为一维
        return i*n+j;
    }
    void initEdge(int x) {
        parent[x]=0;
        onedge[x]=true;
       	ans--;
    }
    void Init() {                              //并查集初始化
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
            if(grid[i][0]==0) {         //第0列
                initEdge(pno(i,0));
            }
            if(grid[i][n-1]==0) {       //第n-1列
                initEdge(pno(i,n-1));
            }
        }
        for (int j=1;j<n-1;j++) {
            if(grid[0][j]==0) {         //第0行
                initEdge(pno(0,j));
            }
            if(grid[m-1][j]==0) {       //第m-1行
                initEdge(pno(m-1,j));
            }
        }
    }
    int Find(int x) {                           //递归算法：并查集中查找x结点的根结点
        if (x!=parent[x])
            parent[x]=Find(parent[x]);          //路径压缩
        return parent[x];
    }
    void Union(int x,int y) {                   //并查集中x和y的两个集合的合并
        int rx=Find(x);
        int ry=Find(y);
        if (rx==ry) return;                           //x和y属于同一棵树的情况
        if (rnk[rx]<rnk[ry]) { 
            parent[rx]=ry;                              //rx结点作为ry的孩子
            onedge[ry]=onedge[ry] | onedge[rx];
        }
        else {
            if (rnk[rx]==rnk[ry]) rnk[rx]++;      //秩相同，合并后rx的秩增1
            parent[ry]=rx;                      //ry结点作为rx的孩子
            onedge[rx]=onedge[rx] | onedge[ry];
        }
        ans--;
    }
};

