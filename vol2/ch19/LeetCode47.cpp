class Solution {
    vector<vector<int>> ans;         //存放nums的全排序
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n=nums.size();
        dfs(nums,n,0);
        return ans;
    }
    void dfs(vector<int>&x,int n,int i) {       //回溯算法
        if (i>=n)                               //到达叶子结点
            ans.push_back(x);
        else {                              //没有到达叶子结点
            for (int j=i;j<n;j++) {         //遍历x[i..n-1]
               if (judge(x,i,j)) continue;    //检测x[j]
                swap(x[i],x[j]);            //i位置置分x[j] 
                dfs(x,n,i+1);                   //进行
                swap(x[i],x[j]);
            }
        }
    }   
    bool judge(vector<int>&x,int i,int j) {      //判断x[j]是否出现在x[i..j-1]中
        if(j>i) {
            for(int k=i;k<j;k++) {            //x[j]是否与x[i..j-1]的元素相同 
                if(x[k]==x[j]) return true;      //若相同则返回真
            }
        }
        return false;                            //全部不相同返回假
    }
};

