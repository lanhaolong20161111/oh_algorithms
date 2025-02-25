struct Point {
    int d;
    int x,y;
    Point(int d1,int x1,int y1) {
        d=d1;
        x=x1;y=y1;
    }
    bool operator<(const Point&s) const {
        return d<s.d;           //用于按照d值递增排序
    }
};
class Solution {
    int dx[4]={0,0,1,-1};           //水平方向偏移量
    int dy[4]={1,-1,0,0};           //垂直方向偏移量
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        vector<vector<int>> dp(m,vector<int>(n,1));
        vector<Point> sa;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                sa.push_back(Point(matrix[i][j],i,j));
            }
        }
        sort(sa.begin(),sa.end());
        int ans=1;              //至少为1
        for(int i=0;i<m*n;i++) {
            int x=sa[i].x,y=sa[i].y;
            for(int di=0;di<4;di++){
                int nx=x+dx[di],ny=y+dy[di];
                if(nx<0 || nx>=m || ny<0 || ny>=n) continue;
                if(matrix[nx][ny]<=matrix[x][y]) continue;
                if(dp[nx][ny]>dp[x][y]) continue;
                dp[nx][ny]=dp[x][y]+1;
                ans=max(ans,dp[nx][ny]);
            }
        }
        return ans;
    }
};

