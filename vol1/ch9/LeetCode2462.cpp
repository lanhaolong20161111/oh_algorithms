class Solution {
    const int INF=0x3f3f3f3f;
public:
    long long totalCost(vector<int>& costs,int k,int candidates) {
        priority_queue<int,vector<int>,greater<>> frontpq, backpq;
        int i=0;
        int j=costs.size()-1;
        long long ans=0;
        while (k--) {							//循环k轮
            while (frontpq.size()<candidates && i<=j) {
                frontpq.push(costs[i]);   //从前面选candidates个工人
                i++;
            }
            while (backpq.size()<candidates && i<=j) {
                backpq.push(costs[j]);    //从后面选candidates个工人
                j--;
            }
            int frontc=!frontpq.empty() ? frontpq.top():INF;
            int backc=!backpq.empty() ? backpq.top():INF;
            if (frontc<=backc) {
                ans+=frontc;                //雇佣代价为frontc的工人
                frontpq.pop();
            }
            else {
                ans+=backc;                 //雇佣代价为backc的工人
                backpq.pop();
            }
        }
        return ans;
    }
};

