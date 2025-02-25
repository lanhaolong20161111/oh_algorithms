struct QNode {                      //���н������
    int p;                          //��ǰλ��
    int back;                      //�ӵ�ǰλ�����������
    QNode() {}
    QNode(int p,int b):p(p),back(b) {}     //���췽��
};
class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a,int b,int x) {
        int MAXX=6000;
        bool visited[MAXX+1][2];
        memset(visited,false,sizeof(visited));
        for (int e:forbidden) {
            visited[e][0]=visited[e][1]=true;
        }
        queue<QNode> qu;     //����һ������qu
        qu.push(QNode(0,0));               //��ʼ�����
        visited[0][0]=true;
        int ans=0;                       //������Ծ����
        while (!qu.empty()) {
            int cnt=qu.size();
            for (int i=0;i<cnt;i++) {
                QNode e=qu.front();qu.pop();         //���ӽ��e
                int curx=e.p;
                int back=e.back;
                if (curx==x) return ans;
                QNode e1;
                e1.p=curx+a;
                e1.back=0;
                if (e1.p<=MAXX && !visited[e1.p][e1.back]) {
                    visited[e1.p][e1.back]=true;
                    qu.push(e1);
                }
                QNode e2;
                e2.p=curx-b;
                e2.back=back+1;
                if (e2.p>=0 && e2.back<2 && !visited[e2.p][e2.back]) {
                    visited[e2.p][e2.back]=true;
                    qu.push(e2);
                }
            }
            ans++;
        }
        return -1;
    }
};

