class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> ans;
        for(int V=0;V<(2<<(n-1));V++) {
            ans.push_back(subs(nums,V));
        }
        return ans;
    }
    vector<int> subs(vector<int>&nums,int V) {
        int n=nums.size();
        vector<int> s;
        for(int j=0;j<n;j++) {      //����о�
            if(inset(V,j)) s.push_back(nums[j]);
        }
        return s; 
    }
    bool inset(int V,int j) {       //�ж��±�j�Ƿ���V��
        return (V & (1<<j))!=0;
    }
};

