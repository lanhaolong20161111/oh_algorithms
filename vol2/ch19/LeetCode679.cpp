class Solution {
    bool ans=false;
public:
    bool judgePoint24(vector<int>& cards) {
        vector<double> a;
        for(int e:cards) a.push_back(e);
        dfs(a);
        return ans;
    }
    void dfs(vector<double>&a) {      //回溯算法
        int n=a.size();
        if(n==1 && fabs(a[0]-24)<0.0001)
            ans=true;
        else if(n>1 && !ans) {
            for(int i=0;i<n;i++) {
                for(int j=0;j<n;j++) {
                    if(i==j) continue;
                    vector<double> b;
                    for(int k=0;k<n;k++) {
                        if(k!=i && k!=j) b.push_back(a[k]);
                    }
                    b.push_back(a[i]+a[j]);         //选择+
                    dfs(b);
                    b.pop_back();       //回溯
                    b.push_back(a[i]-a[j]);         //选择-
                    dfs(b);
                    b.pop_back();       //回溯
                    b.push_back(a[i]*a[j]);         //选择*
                    dfs(b);
                    b.pop_back();       //回溯
                    if(a[j]!=0.0) {     //选择/
                        b.push_back(a[i]/a[j]);
                        dfs(b);
                        b.pop_back();       //回溯
                    }
                }
            }
        }
    }
};

