struct cmp {
    bool operator() (const string&x,const string&y) {
        return x+y>y+x;										//用于定制排序
    }
};
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> a;
        for(int e:nums) a.push_back(to_string(e));
        sort(a.begin(),a.end(),cmp());
        string ans="";
        for(auto e:a) ans+=e;
        if(ans[0]=='0') return "0";
        else return ans;
    }
};

