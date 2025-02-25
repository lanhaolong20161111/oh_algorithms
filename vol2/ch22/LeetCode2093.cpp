struct Edge {                                     //������
    int vno;                                      //�ڽӵ�
    int wt;                                       //�ߵ�Ȩ
    Edge(int v,int w):vno(v),wt(w) {}
};
struct QNode {                  //���ȶ��н������
    int vno;                    //������
    int length;                 //·������
    int disc;                   //���۴���
    bool operator<(const QNode& b) const {
        return length>b.length;     //lengthԽСԽ���ȳ���
    }
};
class Solution {
    const int INF=0x3f3f3f3f;
public:
    int minimumCost(int n,vector<vector<int>>& highways,int discounts) {
        vector<vector<Edge>> adj(n);      //�ڽӱ�
        for(int i=0;i<highways.size();i++) {   //����highways�����ڽӱ�
            int a=highways[i][0];
            int b=highways[i][1];
            int w=highways[i][2];         //<a,b>:w
            adj[a].push_back(Edge(b,w));
            adj[b].push_back(Edge(a,w));
        }
        priority_queue<QNode> pqu;  //����С����pqu,Ԫ��Ϊ[����,vno,���۴���]
        QNode e,e1,e2;
        e.vno=0;e.length=0;e.disc=0;
        pqu.push(e);               					//Դ��Ԫ�ؽ���
        vector<vector<int>> dist(n,vector<int>(discounts+1,INF));
        while(!pqu.empty()) {
            e=pqu.top();pqu.pop();            //���ӽ��e
            int cost=e.length,u=e.vno,disc=e.disc;
            if(disc>discounts) continue;      //��֧�������ۿ۴���ʱ����
            if(u==n-1) return cost;				//�ҵ�Ŀ��
            if(cost<dist[u][disc]) {
                dist[u][disc]=cost;
                for(auto edj:adj[u]) {
                    int v=edj.vno,w=edj.wt;				//�����ۿ�
                    e1.vno=v;e1.length=cost+w;e1.disc=disc;
                    pqu.push(e1);
                    e2.vno=v;e2.length=cost+w/2;e2.disc=disc+1;
                    pqu.push(e2);							//���ۿ�
                }
            }
        }
        return -1;
    }
};

