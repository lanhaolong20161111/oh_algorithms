struct Edge {                                     //������
    int vno;                                      //�ڽӵ�
    int wt;                                       //�ߵ�Ȩ
    Edge(int v,int w):vno(v),wt(w) {}
};
struct QNode {                  //���ȶ��н������
    int vno;                    //������
    int length;                 //·������
    bool operator<(const QNode& b) const {
        return length>b.length;     //lengthԽСԽ���ȳ���
    }
};
class Solution {
    const int INF=0x3f3f3f3f;
public:
    int networkDelayTime(vector<vector<int>>& times,int n,int k) {
        vector<vector<Edge>> adj(n);              //�ڽӱ�
        for(int i=0;i<times.size();i++) {       //����times�����ڽӱ�
            int a=times[i][0]-1;
            int b=times[i][1]-1;
            int w=times[i][2];                  //<a,b>:w
            adj[a].push_back(Edge(b,w));
        }
        int s=k-1;                      //Դ��Ϊs
        vector<int> dist(n,INF);      //����dist����ʼ������Ԫ��ΪINF
        dist[s]=0;
        QNode e,e1;
        priority_queue<QNode> pqu;        //����һ��С����pqu
        e.vno=s;e.length=0;
        pqu.push(e);              //Դ��Ԫ�ؽ���
        while(!pqu.empty()) {                 //���в���ѭ��
            e=pqu.top(); pqu.pop();             //����Ԫ��e
            int u=e.vno;
            for(auto edj:adj[u]) {
                int v=edj.vno;               //���ڶ���Ϊv
                if(dist[u]+edj.wt<dist[v]) {     //���ɳ�:u��v�б���·�����ȸ���
                    dist[v]=dist[u]+edj.wt;
                    e1.vno=v;e1.length=dist[v];
                    pqu.push(e1);              //Ԫ��e1����
                }
            }
        }
        int ans=dist[0];
        for(int i=1;i<n;i++) {
            if(dist[i]>ans) ans=dist[i];
        }
        if(ans==INF) return -1;
        else  return ans;
    }
};

