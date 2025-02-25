struct QNode {                  //队列元素类型
    int x,y;                    //位置
    int length;                 //路径长度
};
class Solution {
    int dx[4]={0,0,1,-1};       //水平方向偏移量
    int dy[4]={1,-1,0,0};       //垂直方向偏移量
public:
    int maximumMinimumPath(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>> dist(m,vector<int>(n,-1));
        queue<QNode> qu;
        QNode e,e1;
        e.x=0;e.y=0;e.length=grid[0][0];
        qu.push(e);
        dist[0][0]=grid[0][0];
        int ans=0;
        while(!qu.empty()) {
            e=qu.front();qu.pop();      //出队元素e
            int x=e.x,y=e.y,length=e.length;
            if(x==m-1 && y==n-1) ans=max(ans,length);
            for(int di=0;di<4;di++) {
                int nx=x+dx[di];
                int ny=y+dy[di];
                if(nx<0 || nx>=m || ny<0 || ny>=n) continue;
                int curlength=min(dist[x][y],grid[nx][ny]);
                if(curlength>dist[nx][ny]) {    //剪支1
                    dist[nx][ny]=curlength;
                    if(dist[nx][ny]>ans) {      //剪支2
                        e1.x=nx;e1.y=ny;e1.length=dist[nx][ny];
                        qu.push(e1);
                    }
                }
            }
        }
        return ans;
    }
};

