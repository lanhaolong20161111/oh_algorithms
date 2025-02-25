class Solution {
// unordered_map<出发城市,map<到达城市,航班次数>> hmap
    unordered_map<string,map<string,int>> hmap;
    vector<string> ans;
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (auto &ft:tickets)      //构造hmap
            hmap[ft[0]][ft[1]]++;
        ans.push_back("JFK");
        int n=tickets.size();       //n个航线
        dfs(n,0);
        return ans;
    }
    bool dfs(int n,int i) {
        if (i==n)
            return true;
        else {
            string from=ans[ans.size()-1];
            for (auto &to:hmap[from]) {
                if (to.second>0 ) {         //存在<from,to>航线
                    ans.push_back(to.first);
                    to.second--;
                    if (dfs(n,i+1)) return true;
                    ans.pop_back();         //回溯
                    to.second++;
                }
            }
        }
        return false;
    }
};

