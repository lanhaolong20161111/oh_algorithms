class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        for(int V=0;V<(2<<(n-1));V++) {
            vector<int> s=subs(n,V);
            if(s.size()==k) ans.push_back(s);
        }
        return ans;
    }
    vector<int> subs(int n,int V) {
        vector<int> s;
        for(int j=0;j<n;j++) {      //����о�
            if(inset(V,j)) s.push_back(j+1);
        }
        return s; 
    }
    bool inset(int V,int j) {       //�ж��±�j�Ƿ���V��
        return (V & (1<<j))!=0;
    }
};

