typedef long long LL;
struct QNode {
    int e;                  //效率
    int s;                  //速度
    QNode() {}
    QNode(int e,int s):e(e),s(s) {}
    bool operator < (const QNode& a) const {
        return s>a.s;           //按s越小越优先出队
    }
};
struct Cmp {
    bool operator()(const QNode& a,const QNode&b) {
        return a.e>b.e;         //按e递减排序
    }
};
class Solution {
    const int MOD=1000000007;
public:
    int maxPerformance(int n,vector<int>& speed,vector<int>& efficiency,int k) {
        vector<QNode> enger;
        for (int i=0;i<n;i++)
            enger .push_back(QNode(efficiency[i],speed[i]));
        sort(enger.begin(),enger.end(),Cmp());
        LL ans=0,sum=0,eff;
        priority_queue<QNode> minpq;
        for (int i=0;i<n;i++) {
            if(minpq.size()>k-1) {
                sum-=minpq.top().s;     //递减sum
                minpq.pop();            //当前区间中最小s出堆
            }
            sum+=enger[i].s;                //当前区间必须包含enger[i]
            eff=enger[i].e;
            ans=max(ans,sum*eff);
            minpq.push(enger[i]);
        }
        return ans % MOD;
    }
};

