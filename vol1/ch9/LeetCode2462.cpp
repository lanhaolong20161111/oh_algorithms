class Solution {
    const int INF=0x3f3f3f3f;
public:
    long long totalCost(vector<int>& costs,int k,int candidates) {
        priority_queue<int,vector<int>,greater<>> frontpq, backpq;
        int i=0;
        int j=costs.size()-1;
        long long ans=0;
        while (k--) {							//ѭ��k��
            while (frontpq.size()<candidates && i<=j) {
                frontpq.push(costs[i]);   //��ǰ��ѡcandidates������
                i++;
            }
            while (backpq.size()<candidates && i<=j) {
                backpq.push(costs[j]);    //�Ӻ���ѡcandidates������
                j--;
            }
            int frontc=!frontpq.empty() ? frontpq.top():INF;
            int backc=!backpq.empty() ? backpq.top():INF;
            if (frontc<=backc) {
                ans+=frontc;                //��Ӷ����Ϊfrontc�Ĺ���
                frontpq.pop();
            }
            else {
                ans+=backc;                 //��Ӷ����Ϊbackc�Ĺ���
                backpq.pop();
            }
        }
        return ans;
    }
};

