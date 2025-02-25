class Solution {
    vector<vector<int>> ans;
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates,int target){
        vector<int> x;
        sort(candidates.begin(),candidates.end());                    //排序以便去重
        dfs(candidates,target,x,0,0);                               //cs和j从0开始
        return ans;
    }
    void dfs(vector<int>&a,int t,vector<int>&x,int cs,int j) {         //回溯算法
        if(cs==t)
            ans.push_back(x);
        else {
            for(int j1=j;j1<a.size();j1++) {
                if(a[j1]+cs>t) continue;                       //超重剪支
                if(j1>j && a[j1]==a[j1-1]) continue;            //跳过重复的元素
                cs+=a[j1];
                x.push_back(a[j1]);
                dfs(a,t,x,cs,j1+1);            //每个元素只能用一次，所以j1+1
                cs-=a[j1];
                x.pop_back();                                  //回溯
            }
        }
    }
};

