class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
    		set<vector<int>> ans;					//用set实现除重
        for(int V=0;V<(2<<(n-1));V++) {
            ans.insert(subs(nums,V));
        }
        vector<vector<int>> ret;    //将ans转换为ret
        for(auto e:ans) ret.push_back(e);
        return ret;
    }
    vector<int> subs(vector<int>&nums,int V) {
        int n=nums.size();
        vector<int> s;
        for(int j=0;j<n;j++) {      //组合列举
            if(inset(V,j)) s.push_back(nums[j]);
        }
        return s;
    }
    bool inset(int V,int j) {       //判断下标j是否在V中
        return (V & (1<<j))!=0;
    }
};

