struct QNode {
    int i;                      //工作i
    vector<int> times;          //times[j]表示工人j的总时间
    int ct;                     //当前的总时间
    bool operator<(const QNode& b) const {
        return ct>b.ct;         //length越小越优先出队
    }
};
class Solution {
    const int INF=0x3f3f3f3f;                       //表示∞
    int ans=INF;
public:
    int minimumTimeRequired(vector<int>& jobs,int k) {
        if(jobs.size()==1)              //特殊情况
            return jobs[0];
        bfs(jobs,k);
        return ans;
    }
    void bfs(vector<int>& jobs,int k) {     //优先队列式分支限界法
        priority_queue<QNode> pqu;
        QNode e,e1;
        e.i=0;                      //建立根结点e
        e.times=vector<int>(k,0);
        e.ct=0;
        pqu.push(e);                //根结点e进队
        while(!pqu.empty()) {
            e=pqu.top();pqu.pop();
            bool flag=true;            //前面没有空闲工人时为true
            for(int j=0;j<k;j++) {
                e1.i=e.i+1;
                e1.times=e.times;
                if(e1.times[j]==0) {
                    if(!flag) continue;         //剪支1：前面有空闲工人时跳过
                    else flag=false;            //前面有空闲工人时置为false
                }
                e1.times[j]+=jobs[e.i];         //任务e.i分配给工人j
                if(e1.times[j]>=ans) continue;      //剪支2
                e1.ct=max(e.ct,e1.times[j]);
                if(e1.ct>=ans) continue;        //剪支2
                if(e1.i==jobs.size())           //e1为一个叶子结点
                    ans=min(e1.ct,ans);
                else
                    pqu.push(e1);
            }
        }
    }
};

