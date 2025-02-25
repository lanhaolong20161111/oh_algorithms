class Solution {
    vector<string> ans;
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,multiset<string>> hmap;
        for (int i=0;i<tickets.size();i++)
            hmap[tickets[i][0]].insert(tickets[i][1]);
        dfs(hmap,"JFK");
        reverse(ans.begin(),ans.end());         //逆置ans
        return ans;
    }
    void dfs(unordered_map<string, multiset<string>>&hmap,string f) {
        while(!hmap[f].empty()) {
            string t=*hmap[f].begin();      				//找到一个航线[f,t]
            hmap[f].erase(hmap[f].begin());   		//删除t
            dfs(hmap,t);
        }
        ans.push_back(f);									//逆序插入f
    }
};

