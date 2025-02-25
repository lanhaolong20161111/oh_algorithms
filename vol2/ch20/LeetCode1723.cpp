struct QNode {
    int i;                      //����i
    vector<int> times;          //times[j]��ʾ����j����ʱ��
    int ct;                     //��ǰ����ʱ��
    bool operator<(const QNode& b) const {
        return ct>b.ct;         //lengthԽСԽ���ȳ���
    }
};
class Solution {
    const int INF=0x3f3f3f3f;                       //��ʾ��
    int ans=INF;
public:
    int minimumTimeRequired(vector<int>& jobs,int k) {
        if(jobs.size()==1)              //�������
            return jobs[0];
        bfs(jobs,k);
        return ans;
    }
    void bfs(vector<int>& jobs,int k) {     //���ȶ���ʽ��֧�޽編
        priority_queue<QNode> pqu;
        QNode e,e1;
        e.i=0;                      //���������e
        e.times=vector<int>(k,0);
        e.ct=0;
        pqu.push(e);                //�����e����
        while(!pqu.empty()) {
            e=pqu.top();pqu.pop();
            bool flag=true;            //ǰ��û�п��й���ʱΪtrue
            for(int j=0;j<k;j++) {
                e1.i=e.i+1;
                e1.times=e.times;
                if(e1.times[j]==0) {
                    if(!flag) continue;         //��֧1��ǰ���п��й���ʱ����
                    else flag=false;            //ǰ���п��й���ʱ��Ϊfalse
                }
                e1.times[j]+=jobs[e.i];         //����e.i���������j
                if(e1.times[j]>=ans) continue;      //��֧2
                e1.ct=max(e.ct,e1.times[j]);
                if(e1.ct>=ans) continue;        //��֧2
                if(e1.i==jobs.size())           //e1Ϊһ��Ҷ�ӽ��
                    ans=min(e1.ct,ans);
                else
                    pqu.push(e1);
            }
        }
    }
};

