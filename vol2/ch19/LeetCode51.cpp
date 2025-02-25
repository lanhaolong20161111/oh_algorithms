class Solution {
    vector<vector<string>> ans;             //������еĽ�
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<int> x;
        for(int i=0;i<n;i++) x.push_back(i);
        dfs(x,n,0);                             //����0��n-1�Ļʺ�
        return ans;
    }
    void dfs(vector<int>&x,int n,int i) {     //�����㷨
        if (i>=n) {                             //���лʺ���ý���
            vector<string> asolution;           //���һ����
            for(int j=0;j<n;j++) {
                string str(n,'.');              //���һ���ʺ�λ�õ��ַ���
                str[x[j]]='Q';
                asolution.push_back(str);
            }
            ans.push_back(asolution);           //��ans�����һ����
        }
        else {
            for(int j=i;j<n;j++) {
                swap(x[i],x[j]);                //����x[i]��x[j]
                if(valid(i,x))                  //��֧
                    dfs(x,n,i+1);
                swap(x[i],x[j]);                //���ݣ�����x[i]��x[j]
            }
        }
    }
    bool valid(int i,vector<int>&x) {       //����(i,x[i])λ���Ƿ���ǰ��Ļʺ󲻳�ͻ
        if (i==0) return true;
        int k=0;
        while (k<i) {                                       //k=0��i-1���ѷ����˻ʺ����
            if ((x[k]==x[i]) || (abs(x[k]-x[i])==abs(k-i))) 
                return false;                                   //(i,x[i])��ʺ�k�г�ͻ
            k++;
        }
        return true;
    }
};

