class Solution {
    vector<vector<int>> ans;        //��Ŵ�
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<int> x=nums;
        dfs(x,0);
        return ans;
    }
    void dfs(vector<int>&x,int i) {     //�����㷨
        int n=x.size();
        if (i>=n)
         ans.push_back(x);
        else {
            for(int j=i;j<n;j++) {
                swap(x[i],x[j]);        //����x[i]��x[j]
                dfs(x,i+1);
                swap(x[i],x[j]);        //���ݣ�����x[i]��x[j]
            }
        }
    }
};

