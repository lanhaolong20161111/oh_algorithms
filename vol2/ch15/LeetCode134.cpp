class Solution {
public:
    int canCompleteCircuit(vector<int>& gas,vector<int>& cost) {
        int n=gas.size();
        int diffsum=0;
        for (int i=0;i<n;i++)
           diffsum+=gas[i]-cost[i];
        if (diffsum<0) return -1;   //加油站的汽油总量小于所有的路程
        int curgas=0;               //记录当前的汽油量
        int i=0;
        int ans=0;                  //存放答案
        while (i<n) {               //遍历每个加油站
            curgas+=gas[i]-cost[i];     //在加油站i加了gas[i]
            if (curgas>=0) i++;         //油箱的汽油是负数
            else {
                curgas=0;           //从加油站i+1重新开始
                ans=i+1;
                i++;
            }
        }
        return ans;
    }
};

