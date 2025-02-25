#include<vector>
#include<iostream>
#include<queue>
using namespace std;

struct Edge {                                     //出边类
    int vno;                                      //邻接点
    int wt;                                       //边的权
    Edge(int v,int w):vno(v),wt(w) {}
};
struct QNode {                  //优先队列结点类型
    int vno;                    //顶点编号
    int length;                 //路径长度
    int nums;                   //中转的城市数
    bool operator<(const QNode& b) const {
        return length>b.length;     //length越小越优先出队
    }
};
class Solution {
    const int INF=0x3f3f3f3f;                                   //表示∞
public:
    int findCheapestPrice(int n,vector<vector<int>>&flights,int src,int dst,int k) {
        vector<vector<Edge>> adj(n);            //邻接表
        for(int i=0;i<flights.size();i++) {   //遍历flights建立邻接表
            int a=flights[i][0];
            int b=flights[i][1];
            int w=flights[i][2];                //<a,b>:w
            adj[a].push_back(Edge(b,w));
        }
        vector<int> dist(n,INF);								//最短路径长度
        vector<int> cnt(n,0);									//最小中转次数
        priority_queue<QNode> pqu;               //小根堆
        QNode e,e1,e2;
        e.vno=src;e.length=0;e.nums=0;
        pqu.push(e);                     //源点元素进队
        dist[src]=0;
        cnt[src]=0;
        while(!pqu.empty()) {
            auto e=pqu.top();pqu.pop();
            int u=e.vno,length=e.length,nums=e.nums;
            if(u==dst) return length;
            if(nums>k) continue;            //剪支
            for(auto edj:adj[u]) {				//扩展
                int v=edj.vno,w=edj.wt;
                if(length+w<dist[v]) {			//剪支：边松驰（合并）
                    dist[v]=length+w;
                    cnt[v]=nums+1;
                    e1.vno=v;e1.length=dist[v];e1.nums=cnt[v];
                    pqu.push(e1);
                }
                else if(nums+1<cnt[v]) {		//尽管路径长度不是更短，但中转次数较少
                    e2.vno=v;e2.length=length+w;
                    e2.nums=nums+1;
                    pqu.push(e2);
                }
            }
        }
        return -1;
    }
};

