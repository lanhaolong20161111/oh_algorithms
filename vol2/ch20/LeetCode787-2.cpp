struct Edge {                                     //������
    int vno;                                      //�ڽӵ�
    int wt;                                       //�ߵ�Ȩ
    Edge(int v,int w):vno(v),wt(w) {}
};
class Solution {
    const int INF=0x3f3f3f3f;                                   //��ʾ��
public:
    int findCheapestPrice(int n,vector<vector<int>>& flights,int src,int dst,int k) {
        vector<vector<Edge>> adj(n);            //�ڽӱ�
        for(int i=0;i<flights.size();i++) {   //����flights�����ڽӱ�
            int a=flights[i][0];
            int b=flights[i][1];
            int w=flights[i][2];         //<a,b>:w
            adj[a].push_back(Edge(b,w));
        }
        vector<int> dist(n,INF);
        dist[src]=0;
        queue<pair<int,int>> qu;		//����Ԫ������Ϊ(vno,length)
        qu.push(pair<int,int>(src,0));
        k+=1;
        while(k-- && !qu.empty()) {
            int cnt=qu.size();
            for(int i=0;i<cnt;i++) {
                pair<int,int> e=qu.front();qu.pop();
                int u=e.first,length=e.second;
                for(auto edj:adj[u]) {
                    int v=edj.vno,w=edj.wt;
                    if(length+w<dist[v]) {      //���ɳ�
                        dist[v]=length+w;
                        qu.push(pair<int,int>(v,dist[v]));
                    }
                }
            }
        }
        if(dist[dst]==INF) return -1;
        return dist[dst];
    }
};

