class Solution {
public:
    vector<string> ans;
    string x;
    vector<string> addOperators(string num,int target) {
        dfs(num,target,0,0,0);
        return ans;
    }
    void dfs(string&num,int target,int i,long long cursum,long long prev) {
        if (i==num.size()) {
            if (cursum==target) ans.push_back(x);
        }
        else {
        string oldx=x;                  //临时保存x
        for (int j=i;j<num.size();j++) {
            if (j!=i && num[i]=='0')    //为前导0时返回
                return; 
            string curs=num.substr(i,j-i+1);		//取出num[i..j]
            long long curd=stoll(curs);				//将curs转换为整数curd
            if (i==0) {
                x+=curs;
                dfs(num,target,j+1,cursum+curd,curd);
                x=oldx;        //回溯(恢复x)
            }
            else  {
                x+='+'+curs;
                dfs(num,target,j+1,cursum+curd,curd);
                x=oldx;        //回溯(恢复x)
                x+='-'+curs;
                dfs(num,target,j+1,cursum-curd,-curd);
                x=oldx;        //回溯(恢复x)
                x+='*'+curs;
                dfs(num,target,j+1,cursum-prev+prev*curd,prev*curd);
                x=oldx;        //回溯(恢复x)
            }
        }
        }
    }
};

