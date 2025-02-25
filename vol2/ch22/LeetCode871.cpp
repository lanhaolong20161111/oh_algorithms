class Solution {
public:
   int minRefuelStops(int target,int startFuel,vector<vector<int>>&stations) {
        int n=stations.size();
        priority_queue<int> pqu;                //大根堆
        int ans=0;
        int fuel=startFuel;                         //当前油量
        int i=0;
        while(i<n) {
            if(fuel>=stations[i][0]) {              //能够到达加油站i
                pqu.push(stations[i][1]);       //将当前加油站的油箱搬走
                i++;                            //继续行驶
            }
            else {                                  //不能够到达加油站i
                if (!pqu.empty()) {
                    fuel+=pqu.top(); pqu.pop();     //选择油量最大的加油
                    ans++;
                }                                   //没有油箱时返回-1
                else return -1;
            }
        }
        while(!pqu.empty() && fuel<target) {    //没有到达目的地时
            fuel+=pqu.top(); pqu.pop();
            ans++;
        }
        if(fuel>=target) return ans;
        return -1;
    }
};

