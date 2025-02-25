class Solution {
    int dx[4]={0,0,1,-1};                        //ˮƽ����ƫ����
    int dy[4]={1,-1,0,0};                       //��ֱ����ƫ����
public:
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();                              //����
        int n=grid[0].size();                           //����
        if (m==0 || n==0) return 0;
        int ans=0;
        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                if (grid[i][j]=='1') {
                    ans++;                          //�ۼƵ���dfs�Ĵ���
                    bfs(grid,i,j);
                }
            }
        }
        return ans;
    }
    void bfs(vector<vector<char>>& grid,int i,int j) { //��(i,j)λ�ó���������ȱ���
        queue<pair<int,int>> qu;                        //����һ������
        grid[i][j]='0';                                     //����(i,j)
        qu.push(pair<int,int>(i,j));                //(i,j)����
        while(!qu.empty()) {                            //�Ӳ���ʱѭ��
            auto e=qu.front(); qu.pop();                //����Ԫ��e
            i=e.first; j=e.second;
            for (int di=0;di<4;di++) {
                int x=i+dx[di];                 //���di��λ������λ��(x,y)
                int y=j+dy[di];
                if (x<0 || x>=grid.size() || y<0 || y>=grid[0].size()) 
                        continue;               //����ʱ����
                if (grid[x][y]=='0')
                        continue;
                grid[x][y]='0';                 //����(x,y)
                qu.push(pair<int,int>(x,y));            //(x,y)����
            }
        }
    }
};

