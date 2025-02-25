class Solution {
    int dx[4]={0,0,1,-1};                   //水平方向偏移量
    int dy[4]={1,-1,0,0};                   //垂直方向偏移量
    vector<int> parent;             //并查集存储结构
    vector<int> rnk;
    int n;
public:
    int shortestBridge(vector<vector<int>>& grid) {
        n=grid.size();                    //求n
        Init();
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j]==0) continue;
                for(int di=0;di<4;di++) {
                    int ni=i+dx[di],nj=j+dy[di];
                    if(ni<0 || ni>=n || nj<0 || nj>=n) continue;
                    if(grid[ni][nj]==0) continue;
                    Union(pno(i,j),pno(ni,nj));     //合并
                }
            }
        }
        int a=-1,b=-1;
        queue<pair<int,int>> qu1,qu2;
        unordered_map<int,int> dist1,dist2;
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j]==0) continue;   //跳过水域
                int cno=pno(i,j);
                int root=Find(cno);
                if(a==-1)
                    a=root;                  //第一次归入A岛
                else if(a!=root && b==-1)
                    b=root;                  //第一次归入B岛
                if(a==root) {                 //归入A岛
                    qu1.push(pair<int,int>(i,j));
                    dist1[cno]=0;
                }
                else if(b==root) {               //归入A岛
                    qu2.push(pair<int,int>(i,j));
                    dist2[cno]=0;
                }
            }
        }
        while(!qu1.empty() && !qu2.empty()) {       //双向多起点BFS
            int ans=-1;
            if(qu1.size()<qu2.size())
                ans=extend(qu1,dist1,dist2);
            else
                ans=extend(qu2,dist2,dist1);
            if(ans!=-1)return ans-1;
        }
        return -1;
    }
    int pno(int i,int j) {                //二维转换为一维
        return i*n+j;
    }

    void Init() {                     //并查集初始化
        parent=vector<int>(n*n+5);
        rnk=vector<int>(n*n+5);
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                int k=pno(i,j);
                parent[k]=k;
                rnk[k]=0;
            }
        }
    }

    int Find(int x) {                  		//并查集中查找x结点的根结点
        if(x!=parent[x])
            parent[x]=Find(parent[x]);  		//路径压缩
        return parent[x];
    }

    void Union(int x,int y) {                //合并
        int rx=Find(x);
        int ry=Find(y);
        if(rx==ry) return;               //x和y属于同一棵树的情况
        if(rnk[rx]<rnk[ry])
            parent[rx]=ry;          //rx结点作为ry的孩子
        else {
            if(rnk[rx]==rnk[ry])
                rnk[rx]++;         //秩相同，合并后rx的秩增1
            parent[ry]=rx;          //ry结点作为rx的孩子
        }
    }

    int extend(queue<pair<int,int>>&qu,unordered_map<int,int>&dist1,unordered_map<int,int>&dist2) {
        int cnt=qu.size();
        for(int i=0;i<cnt;i++) {
            auto e=qu.front();qu.pop();
            int x=e.first,y=e.second;
            int cdist=dist1[pno(x,y)];
            for(int di=0;di<4;di++) {
                int nx=x+dx[di],ny=y+dy[di];
                int no=pno(nx,ny);
                if(nx<0 || nx>=n || ny<0 || ny>=n) continue;
                if(dist1.count(no)) continue;
                if(dist2.count(no)) return cdist+1+dist2[no];
                qu.push(pair<int,int>(nx,ny));
                dist1[no]=cdist+1;
            }
        }
        return -1;
    }
};

