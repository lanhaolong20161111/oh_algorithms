class Solution {
    int dx[4]={0,0,1,-1};                        //ˮƽ����ƫ����
    int dy[4]={1,-1,0,0};                       //��ֱ����ƫ����
    queue<pair<int,int>> qu;
    vector<vector<bool>> visited;
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n=grid.size();
        visited=vector<vector<bool>>(n,vector<bool>(n,false));
        int cnt=0;
        for (int i=0;i<n;i++) {
            for (int j=0;j<n;j++) {
                if (grid[i][j]==1) {            //½�ص�Ԫ
                    qu.push(pair<int,int>(i,j));
                    visited[i][j]=true;
                    cnt++;
                }
            }
        }
        if(cnt==n*n) return -1;     //ȫ��Ϊ½�ص����
        else return bfs(grid);
    }
    int bfs(vector<vector<int>>&grid) {    //�����ֲ�ι����������
        int n=grid.size();
        int step=0;
        while(!qu.empty()) {
            int cnt=qu.size();
            for(int i=0;i<cnt;i++) {
                auto e=qu.front();qu.pop();
                int x=e.first,y=e.second;
                for(int di=0;di<4;di++) {
                    int nx=x+dx[di];
                    int ny=y+dy[di];
                    if (nx<0 || nx>=n || ny<0 || ny>=n)
                        continue;
                    if(visited[nx][ny]) continue;		//�����ѷ��ʵĵ�Ԫ
                    if(grid[nx][ny]==1) continue;		//����½�ص�Ԫ
                    visited[nx][ny]=true;
                    qu.push(pair<int,int>(nx,ny));
                }
            }
            step++;												//��չ�����1
        }
        return step-1;
    }
};

