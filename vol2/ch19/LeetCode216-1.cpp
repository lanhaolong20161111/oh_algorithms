class Solution {
    vector<vector<int>> ans;
public:
    vector<vector<int>> combinationSum3(int k,int n) {
        int cnt=0;
        vector<int> x;
        dfs(n,k,0,x,cnt,1);                             //i��1��ʼ
        return ans;
    }
    void dfs(int n,int k,int cs,vector<int>& x,int cnt,int i){      //�����㷨
        if (i>=10) {                                        //�ҵ�һ��Ҷ�ӽ��
            if (cs==n && cnt==k)                        //�ҵ�һ�����������Ľ�
                ans.push_back(x);
        }
        else {                                  //û�е���Ҷ�ӽ��
            x.push_back(i);                     //ѡȡ����i 
            cnt++;
            dfs(n,k,cs+i,x,cnt,i+1);
            cnt--;                              //����
            x.pop_back();
            dfs(n,k,cs,x,cnt,i+1);                  //��ѡȡ����i
        }
    }
};

