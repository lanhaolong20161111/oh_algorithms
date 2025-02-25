class Solution {
    vector<vector<int>> ans;
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates,int target){
        vector<int> x;
        sort(candidates.begin(),candidates.end());                    //�����Ա�ȥ��
        dfs(candidates,target,x,0,0);                               //cs��j��0��ʼ
        return ans;
    }
    void dfs(vector<int>&a,int t,vector<int>&x,int cs,int j) {         //�����㷨
        if(cs==t)
            ans.push_back(x);
        else {
            for(int j1=j;j1<a.size();j1++) {
                if(a[j1]+cs>t) continue;                       //���ؼ�֧
                if(j1>j && a[j1]==a[j1-1]) continue;            //�����ظ���Ԫ��
                cs+=a[j1];
                x.push_back(a[j1]);
                dfs(a,t,x,cs,j1+1);            //ÿ��Ԫ��ֻ����һ�Σ�����j1+1
                cs-=a[j1];
                x.pop_back();                                  //����
            }
        }
    }
};

