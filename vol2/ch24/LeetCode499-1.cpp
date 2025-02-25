class Solution {
    const int INF=0x3f3f3f3f;
    int m,n;
    vector<vector<int>> dist;
    vector<vector<string>> path;
    int dr[4]={1, 0, 0, -1};                        //垂直方向偏移量
    int dc[4]={0, -1,1, 0};                         //水平方向偏移量
    vector<string> dirstr={"d","l","r","u"};    //方位：字典序最小
    int hr,hc;                                      //洞的位置
public:
	string findShortestWay(vector<vector<int>>&maze,vector<int>&ball,vector<int>&hole) {
        m=maze.size(),n=maze[0].size();
        dist=vector<vector<int>>(m,vector<int>(n,INF));
        path=vector<vector<string>>(m,vector<string>(n,""));
        int sr=ball[0],sc=ball[1];
        hr=hole[0]; hc=hole[1];
        dist[sr][sc]=0;
        dfs(maze,sr,sc);
        return dist[hr][hc]==INF?"impossible":path[hr][hc];
    }
    void dfs(vector<vector<int>>&maze,int r,int c) {
        for (int di=0;di<4;di++) {
            int delta=0;
            int nr=r, nc=c;
            while(nr+dr[di]>=0 && nr+dr[di]<m 
                    && nc+dc[di]>=0 && nc+dc[di]<n
                    && maze[nr+dr[di]][nc+dc[di]]==0) {  //按di方向滚动
                nr+=dr[di];
                nc+=dc[di];
                delta++;
                if (nr==hr && nc==hc)     //(nr,nc)为洞
                    break;
            }
            int curdist=dist[r][c]+delta;
            string curpath=path[r][c]+dirstr[di];
            if (curdist<dist[nr][nc]) {         //边松驰
                dist[nr][nc]=curdist;
                path[nr][nc]=curpath;
                if(nr!=hr || nc!=hc)         //(nr,nc)不是洞
                    dfs(maze,nr,nc);
            }
            else if(curdist==dist[nr][nc]) {	//路径长度相同时
                if(curpath<path[nr][nc]) {      //找最小序路径
                    path[nr][nc]=curpath;
                    if(nr!=hr || nc!=hc)         //(nr,nc)不是洞
                        dfs(maze,nr,nc);
                }
            }
        }
    }
};

