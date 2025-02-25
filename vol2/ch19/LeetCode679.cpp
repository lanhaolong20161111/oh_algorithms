class Solution {
    bool ans=false;
public:
    bool judgePoint24(vector<int>& cards) {
        vector<double> a;
        for(int e:cards) a.push_back(e);
        dfs(a);
        return ans;
    }
    void dfs(vector<double>&a) {      //�����㷨
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
                    b.push_back(a[i]+a[j]);         //ѡ��+
                    dfs(b);
                    b.pop_back();       //����
                    b.push_back(a[i]-a[j]);         //ѡ��-
                    dfs(b);
                    b.pop_back();       //����
                    b.push_back(a[i]*a[j]);         //ѡ��*
                    dfs(b);
                    b.pop_back();       //����
                    if(a[j]!=0.0) {     //ѡ��/
                        b.push_back(a[i]/a[j]);
                        dfs(b);
                        b.pop_back();       //����
                    }
                }
            }
        }
    }
};

