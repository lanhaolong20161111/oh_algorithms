typedef long long LL;
struct QNode {
    int e;                  //Ч��
    int s;                  //�ٶ�
    QNode() {}
    QNode(int e,int s):e(e),s(s) {}
    bool operator < (const QNode& a) const {
        return s>a.s;           //��sԽСԽ���ȳ���
    }
};
struct Cmp {
    bool operator()(const QNode& a,const QNode&b) {
        return a.e>b.e;         //��e�ݼ�����
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
                sum-=minpq.top().s;     //�ݼ�sum
                minpq.pop();            //��ǰ��������Сs����
            }
            sum+=enger[i].s;                //��ǰ����������enger[i]
            eff=enger[i].e;
            ans=max(ans,sum*eff);
            minpq.push(enger[i]);
        }
        return ans % MOD;
    }
};

