class Solution {
    vector<int> ans;
    vector<int> used;       //used[i]��ʾi�Ƿ�ʹ�ù�
    int cnt=0;
public:
    string getPermutation(int n,int k) {
        vector<int> x(n);
        used=vector<int>(n+1,0);
        dfs(x,0,k);
        string ret="";              //��ansת��Ϊ�ַ���ret
        for(int e:ans) ret+=to_string(e);
        return ret; 
    }
    bool dfs(vector<int>&x,int i,int k) {   //�����㷨
        int n=x.size();
        if (i>=n) {
            cnt++;                          //�ۼ��ҵ������и���
            if(cnt==k) {                    //�ҵ���k������
                ans=x;
                return true;
            }
        }
        else {
            for(int j=1;j<=n;j++) {
                if(used[j]) continue;                   //��֧�������Ѿ�ʹ�ù���j
                x[i]=j;
                used[j]=1;                              //ѡ��j
                if(dfs(x,i+1,k))
                    return true;
                used[j]=0;                              //����
                x[i]=-1;
            }
        }
        return false;
    }
};

