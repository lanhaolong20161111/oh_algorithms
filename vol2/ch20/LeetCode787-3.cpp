struct Edge {                                     //������
    int vno;                                      //�ڽӵ�
    int wt;                                       //�ߵ�Ȩ
    Edge(int v,int w):vno(v),wt(w) {}
};
struct QNode {                  //���ȶ��н������
    int vno;                    //������
    int length;                 //·������
    int nums;                   //��ת�ĳ�����
    bool operator<(const QNode& b) const {
        return length>b.length;     //lengthԽСԽ���ȳ���
    }
};
class Solution {
    const int INF=0x3f3f3f3f;                   //��ʾ��
public:
    int findCheapestPrice(int n,vector<vector<int>>&flights,int src,int dst,int k) {
        vector<vector<Edge>> adj(n);            //�ڽӱ�
        for(int i=0;i<flights.size();i++) {   //����flights�����ڽӱ�
            int a=flights[i][0];
            int b=flights[i][1];
            int w=flights[i][2];                //<a,b>:w
            adj[a].push_back(Edge(b,w));
        }
        vector<int> dist(n,INF);
        vector<int> cnt(n,0);
        priority_queue<QNode> pqu;          //С����
        QNode e,e1;
        e.vno=src;e.length=0;e.nums=0;
        pqu.push(e);                        //Դ��Ԫ�ؽ���
        dist[src]=0;
        cnt[src]=0;
        int ans=INF;
        while(!pqu.empty()) {
            auto e=pqu.top();pqu.pop();
            int u=e.vno,length=e.length,nums=e.nums;
            if(u==dst) return ans=min(ans,length);
            for(auto edj:adj[u]) {
                int v=edj.vno,w=edj.wt;
                e1.vno=v; e1.nums=nums+1;
                if(e1.nums>k+1) continue;   			//��֧1
                if(length+w<dist[v] || e1.nums<cnt[v]) {//��֧2
                    dist[v]=length+w;
                    cnt[v]=e1.nums;
                    e1.length=dist[v];
                    if(dist[v]>ans) continue;//��֧3
                    pqu.push(e1);
                }
            }
        }
        if(ans==INF) return -1;
        return ans;
    }
};

