class Solution {
    int m,n;
    vector<vector<char>> grid;
    int ans;                    //存放岛屿的数量
    vector<int> parent;         //并查集存储结构
    vector<int> rnk;            //子树的秩(与高度成正比)
public:
    int numIslands(vector<vector<char>>& grid) {
        m=grid.size(); n=grid[0].size();
        this->grid=grid;
        ans=0;
        Init();
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j]=='1') {
                    if(j<n-1 && grid[i][j+1]=='1')        //grid[i][j+1]为1
                        Union(pno(i,j),pno(i,j+1));     //(i,j)和(i,j+1)合并
                    if(i<m-1 && grid[i+1][j]=='1')        //grid[i+1][j]为1
                        Union(pno(i,j),pno(i+1,j));     //(i+1,j)和(i,j)合并
                }
            }
        }
        return ans;
    }
     int pno(int i,int j) {       //二维转换为一维
        return i*n+j;
    }
    void Init() {                              //并查集初始化
        parent=vector<int>(m*n,0);
        rnk=vector<int>(m*n,0);
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j]=='1') {
                    int k=pno(i,j);
                    parent[k]=k;
                    rnk[k]=0;
                    ans++;
                }
            }
        }
    }
    int Find(int x) {                               //递归算法：并查集中查找x结点的根结点
        if (x!=parent[x])
            parent[x]=Find(parent[x]);          //路径压缩
        return parent[x];
    }
    void Union(int x,int y) {                       //并查集中x和y的两个集合的合并
        int rx=Find(x);
        int ry=Find(y);
        if (rx==ry) return;                           //x和y属于同一棵树的情况
        if (rnk[rx]<rnk[ry])
            parent[rx]=ry;                              //rx结点作为ry的孩子
        else {
            if (rnk[rx]==rnk[ry]) rnk[rx]++;      //秩相同，合并后rx的秩增1
            parent[ry]=rx;                      //ry结点作为rx的孩子
        }
        ans--;
    }
};

