struct QNode {                                                //���ȶ��н������
  int x,y;                                                        //0��λ��
      string grid;                                                  //�����ַ���
      int f,g,h;                                                      //����ʽ����ֵ
    bool operator<(const QNode &s) const  {         //����<��ϵ����
          return f>s.f;                                           //fԽСԽ���ȳ���
      }
};
class Solution {
  int dx[4]={0,0,1,-1};                                     //ˮƽ����ƫ����
      int dy[4]={1,-1,0,0};                                     //��ֱ����ƫ����
      string goal="123450";
public:
      int slidingPuzzle(vector<vector<int>>& board) {
          int m=2,n=3;
          string s; 
          int x,y;
          for (int i=0;i<m;i++) {                                 //��boardת��Ϊs���ҵ�0��λ��
              for (int j=0;j<n;j++) {
                  s.push_back(board[i][j]+'0');
                  if (board[i][j]==0) x=i,y=j;
              }
          }
          if (s==goal) return 0;
          unordered_set<string> visited;
          priority_queue<QNode> pqu;
          QNode e,e1;
          e.x=x; e.y=y; e.grid=s;
          e.g=0; e.h=geth(s);               //����e.h=0
          e.f=e.g+e.h;
          pqu.push(e);                                            //��ʼ״̬����
          visited.insert(e.grid);                                 //��ǳ�ʼ״̬�ѷ���
          while (!pqu.empty()) {
            e=pqu.top(); pqu.pop();
              x=e.x;y=e.y;s=e.grid;
              int p0=x*n+y;
              for (int di=0;di<4;di++) {
                int nx=x+dx[di],ny=y+dy[di];
                  if (nx<0 || nx>=m || ny<0 || ny>=n) continue;
                    int p1=nx*n+ny;
                    swap(s[p0],s[p1]);					//�ƶ�һ��
                    if (goal==s) return e.g+1;		//�ҵ�Ŀ��״̬
                    if (!visited.count(s)) {
                        visited.insert(s);
                        e1.x=nx; e1.y=ny; e1.grid=s;
                        e1.g=e.g+1;
                        e1.h=geth(s);
                        e1.f=e1.g+e1.h;
                        pqu.push(e1);
                    }
                    swap(s[p0],s[p1]);                    //�ָ�s
                  }
          }
          return -1;                                            //û���ҵ�����false
      }
      int geth(string &s) {                                   //��������ʽ����ֵ
          int h=0;
          for(int i=0;i<6;i++) {
              if(s[i]!='0' && goal[i]!=s[i]) h++;
          }
          return h;
      }
};

