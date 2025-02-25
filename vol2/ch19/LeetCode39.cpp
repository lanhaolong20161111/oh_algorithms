class Solution {
    vector<vector<int>> ans;
public:
    vector<vector<int>> combinationSum(vector<int>& candidates,int target) {
        vector<int> x;
        dfs(candidates,target,x,0);                         //i��0��ʼ
        return ans;
    }
    void dfs(vector<int>&a,int rt,vector<int>& x,int i) {   //�����㷨
        if(rt==0) {                     //�ҵ�һ����
            ans.push_back(x);
        }
        else if(i<a.size()) {           //a��δ�������
            dfs(a,rt,x,i+1);            //��ѡ��a[i]
            if(a[i]<=rt) {              //������ʱѡ��a[i]
                x.push_back(a[i]);
                dfs(a,rt-a[i],x,i);
                x.pop_back();
            }
        }
    }
};

