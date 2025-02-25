class Solution {
    int dx[4]={0,0,1,-1};                        //ˮƽ����ƫ����
    int dy[4]={1,-1,0,0};                       //��ֱ����ƫ����
public:
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();                      //����
        int n=grid[0].size();                   //����
        int ans=0;
        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                if (grid[i][j]=='1') {
                    ans++;                      //�ۼƵ���dfs�Ĵ���
                    dfs(grid,i,j);
                }
            }
        }
        return ans;
    }
    void dfs(vector<vector<char>>& grid,int i,int j) {  //��(i,j)λ�ó���������ȱ���
        grid[i][j]='0';                                 //����(i,j)
        for (int di=0;di<4;di++) {
            int x=i+dx[di];                             //���di��λ������λ��(x,y)
            int y=j+dy[di];
            if (x<0 || x>=grid.size() || y<0 || y>=grid[0].size()) 
                continue;                               //����ʱ����
            if (grid[x][y]=='0')
                continue;
            dfs(grid,x,y);
        }
    }
};

