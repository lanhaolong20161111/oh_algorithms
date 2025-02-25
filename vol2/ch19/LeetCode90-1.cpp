class Solution {
    set<vector<int>> s;						//sΪSTL�������������ڳ���
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> x;
        dfs(nums,x,0);
        vector<vector<int>> ans;					//������s��Ԫ����ӵ�ans��
        for(auto e: s)
            ans.push_back(e);
        return ans;
    }
    void dfs(vector<int> &a,vector<int>&x,int i) {              //�����㷨
        if (i>=a.size())                                   //����һ��Ҷ�ӽ��
            s.insert(x);
        else {
            x.push_back(a[i]);                         //ѡ��a[i]
            dfs(a,x,i+1);
            x.pop_back();
            dfs(a,x,i+1);                         //��ѡ��a[i]
        }
    }
};

