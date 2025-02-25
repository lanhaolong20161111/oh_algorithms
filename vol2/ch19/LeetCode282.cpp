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
        string oldx=x;                  //��ʱ����x
        for (int j=i;j<num.size();j++) {
            if (j!=i && num[i]=='0')    //Ϊǰ��0ʱ����
                return; 
            string curs=num.substr(i,j-i+1);		//ȡ��num[i..j]
            long long curd=stoll(curs);				//��cursת��Ϊ����curd
            if (i==0) {
                x+=curs;
                dfs(num,target,j+1,cursum+curd,curd);
                x=oldx;        //����(�ָ�x)
            }
            else  {
                x+='+'+curs;
                dfs(num,target,j+1,cursum+curd,curd);
                x=oldx;        //����(�ָ�x)
                x+='-'+curs;
                dfs(num,target,j+1,cursum-curd,-curd);
                x=oldx;        //����(�ָ�x)
                x+='*'+curs;
                dfs(num,target,j+1,cursum-prev+prev*curd,prev*curd);
                x=oldx;        //����(�ָ�x)
            }
        }
        }
    }
};

