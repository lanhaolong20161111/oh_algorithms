class Solution {
    vector<string>ans;          //存放全部结果串
    string x;                   //解向量(一个有效括号串)
public:
    vector<string> generateParenthesis(int n) {
        x="";
        dfs(n,0,0);
        return ans;
    }
    void dfs(int n,int left,int right) {    //回溯算法
        if (x.size()==2*n) {
            ans.push_back(x);       //将有效括号串添加到ans中
        }
        else {
            if(left<n) {
                x.push_back('(');       //选择'('
                dfs(n,left+1,right);
                x.pop_back();           //回溯
            }
            if(right<left) {
                x.push_back(')');       //选择')'
                dfs(n,left,right+1);
                x.pop_back();           //回溯 
            }
        }
    }
};

