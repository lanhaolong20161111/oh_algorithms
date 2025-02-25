class Solution {
    int dr[4]={0,0,-1,1};            //ˮƽ����ƫ����
    int dc[4]={-1,1,0,0};            //��ֱ����ƫ����
public:
    bool hasPath(vector<vector<int>>& maze,vector<int>& start,vector<int>& dest) {
        int m=maze.size(),n=maze[0].size();
        auto visited=vector<vector<bool>>(m,vector<bool>(n,false));
        queue<pair<int,int>> qu;
        pair<int,int> e,e1;
        e=pair<int,int>(start[0],start[1]);
        qu.push(e);
        visited[e.first][e.second]=true;
        while (!qu.empty()) {
            e=qu.front(); qu.pop();
            int r=e.first,c=e.second;
            if(r==dest[0] && c==dest[1])
                return true;
            for (int di=0;di<4;di++) {
                int nr=r,nc=c;
                while(nr+dr[di]>=0 && nr+dr[di]<m && 
                        nc+dc[di]>=0 && nc+dc[di]<n  && 
                        maze[nr+dr[di]][nc+dc[di]]==0) {    //һֱ����ȥ
                    nr+=dr[di];nc+=dc[di];
                }                            //��di�������(nr,nc)
                if (visited[nr][nc]) continue;
                visited[nr][nc]=true;
                e1=pair<int,int>(nr,nc);
                qu.push(e1);
            }
        }
        return false;
    }
};

