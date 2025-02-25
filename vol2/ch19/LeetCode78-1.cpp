class Solution {
    vector<vector<int>> ans;
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> x;
        dfs(nums,x,0);
        return ans;
    }
    void dfs(vector<int>&a,vector<int>&x,int i) {   //�����㷨
        if (i>=a.size())                            //����һ��Ҷ�ӽ��
            ans.push_back(x);                     //���Ӽ�x��ӵ�ans��
        else {
            x.push_back(a[i]);                      //ѡ��a[i]
            dfs(a,x,i+1);
            x.pop_back();                       //����
            dfs(a,x,i+1);               //��ѡ��a[i]
        }
    }
};

