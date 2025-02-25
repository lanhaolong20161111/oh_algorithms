class Solution {
    vector<vector<int>> ans;        //��Ŵ�
    vector<int> used;
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        used=vector<int>(n,0);
        vector<int> x;
        dfs(nums,x,0);
        return ans;
    }
    void dfs(vector<int>&a,vector<int>&x,int i) {   //�����㷨
        int n=a.size();
        if (i>=n)
            ans.push_back(x);
        else {
            for(int j=0;j<n;j++) {
                if(used[j]) continue;               //��֧�������Ѿ�ʹ�ù���a[j]
                x.push_back(a[j]);
                used[j]=1;                          //ѡ��a[j]
                dfs(a,x,i+1);                       //ת���ռ�������һ��
                used[j]=0;                          //����
                x.pop_back();
            }
        }
    }
};

