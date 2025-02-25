class Solution {
// unordered_map<��������,map<�������,�������>> hmap
    unordered_map<string,map<string,int>> hmap;
    vector<string> ans;
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (auto &ft:tickets)      //����hmap
            hmap[ft[0]][ft[1]]++;
        ans.push_back("JFK");
        int n=tickets.size();       //n������
        dfs(n,0);
        return ans;
    }
    bool dfs(int n,int i) {
        if (i==n)
            return true;
        else {
            string from=ans[ans.size()-1];
            for (auto &to:hmap[from]) {
                if (to.second>0 ) {         //����<from,to>����
                    ans.push_back(to.first);
                    to.second--;
                    if (dfs(n,i+1)) return true;
                    ans.pop_back();         //����
                    to.second++;
                }
            }
        }
        return false;
    }
};

