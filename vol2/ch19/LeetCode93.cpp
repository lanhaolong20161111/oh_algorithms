class Solution {
    vector<string> ans;
    int x[4];
public:
    vector<string> restoreIpAddresses(string s) {
        dfs(s,0,0);
        return ans;
    }
    void dfs(string&s,int cnt,int i) {     //�����㷨
        int n=s.size();
        if((n-i>(4-cnt)*3) || (n-i<(4-cnt))) //��֧
            return;
        if(i==n) {                      //����һ��Ҷ�ӽ��
            if(cnt==4) {                //�ҵ�һ����
            string tmp="";                  //��xת��Ϊ�ַ���
            for(int j=0;j<4;j++) {
                tmp+=to_string(x[j]);
                if(j!=3) tmp+='.';
             }
             ans.push_back(tmp);
            }
        }
        else {
        if (s[i]=='0') {        //������ǰ����
           x[cnt]=0;            //����ǰΪ'0'�������IP��ַֻ��Ϊ0
           dfs(s,cnt+1,i+1);
        }
        int d=0;
        for (int j=i;j<min(i+3,n);j++) {    //��̽j��ÿ�����ܵ�λ��
            d=d*10+(s[j]-'0');   
            if (d>0 && d<=255) {    //��֧
                x[cnt]=d;
                dfs(s,cnt+1,j+1);
            }
            else return;            //��Чdʱ����
        }
        }
    }
};

