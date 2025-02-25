struct Edge {                                     //������
    int vno;                                      //�ڽӵ�
    int wt;                                       //�ߵ�Ȩ
    Edge(int v,int w):vno(v),wt(w) {}
};
struct QNode {                  //����Ԫ������
    int vno;                    	//������
    int length;                 	//·������
    int nums;                   	//��ת�ĳ�����
};
class Solution {
    const int INF=0x3f3f3f3f;                                   //��ʾ��
public:
    int findCheapestPrice(int n,vector<vector<int>>&flights,int src,int dst,int k) {
        vector<vector<Edge>> adj(n);            //�ڽӱ�
        for(int i=0;i<flights.size();i++) {   //����flights�����ڽӱ�
            int a=flights[i][0];
            int b=flights[i][1];
            int w=flights[i][2];         //<a,b>:w
            adj[a].push_back(Edge(b,w));
        }
        queue<QNode> qu;               //�������qu
        QNode e,e1;
        e.vno=src;e.length=0;e.nums=0;
        qu.push(e);                     //Դ��Ԫ�ؽ���
        vector<int> dist(n,INF);
        dist[src]=0;
        int ans=INF;
        while(!qu.empty()) {
            e=qu.front();qu.pop();      //����Ԫ��e
            int u=e.vno,length=e.length,nums=e.nums;
            if(u==dst) ans=min(ans,length); 		//�ҵ�Ŀ��
            for(auto edj:adj[u]) {
                int v=edj.vno,w=edj.wt;
                e1.vno=v;e1.nums=nums+1;
                if(e1.nums>k+1) continue;       //��֧1
                if(length+w<dist[v]) {          //��֧2�����ɳ�
                    dist[v]=length+w;
                    if(dist[v]<ans) {           //��֧3
                        e1.length=dist[v];
                        qu.push(e1);
                    }
                }
            }
        }
        if(ans==INF) return -1;
        return ans;
    }
};

