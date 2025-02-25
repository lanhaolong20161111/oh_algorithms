class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
    		set<vector<int>> ans;					//��setʵ�ֳ���
        for(int V=0;V<(2<<(n-1));V++) {
            ans.insert(subs(nums,V));
        }
        vector<vector<int>> ret;    //��ansת��Ϊret
        for(auto e:ans) ret.push_back(e);
        return ret;
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

