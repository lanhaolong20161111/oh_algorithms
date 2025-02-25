class Solution {
    vector<vector<int>> ans;
public:
    vector<vector<int>> combinationSum3(int k,int n) {
        vector<int> x(k);
        dfs(n,k,0,x,0);             //i��0��ʼ
        return ans;
    }
    void dfs(int n,int k,int cs,vector<int>& x,int i){  //�����㷨
        if (i>=k) {                         //�ҵ�һ��Ҷ�ӽ��
            if (cs==n)                      //�ҵ�һ�����������Ľ�
                ans.push_back(x);
        }
        else {                                  //û�е���Ҷ�ӽ��
            for(int j=1;j<=9;j++) {
                if(i>0 && j<=x[i-1]) continue;
                x[i]=j;
                dfs(n,k,cs+j,x,i+1);
            }
        }
    }
};

