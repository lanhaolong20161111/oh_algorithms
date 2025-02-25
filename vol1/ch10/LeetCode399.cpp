class Solution {
    vector<int> parent;
    vector<double> weight;
public:
    vector<double> calcEquation(vector<vector<string>>& equations,vector<double>&values, vector<vector<string>>&queries) {
        int n=equations.size();
        Init(2*n);
        int id=0;                           //给不同变量从0开始编号
        unordered_map<string,int> hmap;
        int x,y;
        for(int i=0;i<n;i++) {
            if(hmap.count(equations[i][0])==0)
                hmap[equations[i][0]]=id++;
            if(hmap.count(equations[i][1])==0)
                hmap[equations[i][1]]=id++;
            x=hmap[equations[i][0]];
            y=hmap[equations[i][1]];
            Union(x,y,values[i]);
        }
        int m=queries.size();
        vector<double> ans(m);              //存放答案
        for(int i=0;i<m;i++) {
            if(hmap.count(queries[i][0])==0 || hmap.count(queries[i][1])==0) {
                ans[i]=-1.0;
                continue;
            }
            x=hmap[queries[i][0]];
            y=hmap[queries[i][1]];
            int rx=Find(x);
            int ry=Find(y);
            if (rx==ry) ans[i]=weight[x]/weight[y];
            else ans[i]=-1.0;
        }
        return ans;
    }
    void Init(int n) {
        parent=vector<int>(n);
        weight=vector<double>(n);
        for (int i=0;i<n;i++) {
            parent[i]=i;
            weight[i]=1.0;
        }
    }
    int Find(int x) {
        if(x!=parent[x]) {
            int origin=parent[x];
            parent[x]=Find(parent[x]);
            weight[x]*=weight[origin];
        }
        return parent[x];
    }

    void Union(int x,int y,double val){
        int rx=Find(x);
        int ry=Find(y);
        if(rx==ry) return;
        parent[rx]=ry;
        weight[rx]=val*weight[y]/weight[x];
    }
};

