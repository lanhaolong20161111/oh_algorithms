class Solution {
    vector<int> parent;         //并查集
public:
    string smallestEquivalentString(string s1,string s2,string baseStr) {
        Init(26);
        for(int i=0;i<s1.size();i++) {
            int x=s1[i]-'a';
            int y=s2[i]-'a';
            Union(x,y);
        }
        string ans="";
        for(int i=0;i<baseStr.size();i++) {
            int x=baseStr[i]-'a';
            int rx=Find(x);
            ans+=(char)(rx+'a');
        }
        return ans;
    }
    void Init(int n) {                              //并查集初始化
        parent=vector<int>(n);
        for (int i=0;i<n;i++)
            parent[i]=i;
    }

    int Find(int x) {                             //递归算法：并查集中查找x结点的根结点
        if (x!=parent[x])
            parent[x]=Find(parent[x]);          //路径压缩
        return parent[x];
    }
    void Union(int x,int y) {                       //并查集中x和y的两个集合的合并
        int rx=Find(x);
        int ry=Find(y);
        if (rx==ry) return;                           //x和y属于同一棵树的情况
        if (rx<ry)  parent[ry]=rx;                 //较小编号的结点作为根
        else  parent[rx]=ry;
    }
};

