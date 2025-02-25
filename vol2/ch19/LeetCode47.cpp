class Solution {
    vector<vector<int>> ans;         //���nums��ȫ����
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n=nums.size();
        dfs(nums,n,0);
        return ans;
    }
    void dfs(vector<int>&x,int n,int i) {       //�����㷨
        if (i>=n)                               //����Ҷ�ӽ��
            ans.push_back(x);
        else {                              //û�е���Ҷ�ӽ��
            for (int j=i;j<n;j++) {         //����x[i..n-1]
               if (judge(x,i,j)) continue;    //���x[j]
                swap(x[i],x[j]);            //iλ���÷�x[j] 
                dfs(x,n,i+1);                   //����
                swap(x[i],x[j]);
            }
        }
    }   
    bool judge(vector<int>&x,int i,int j) {      //�ж�x[j]�Ƿ������x[i..j-1]��
        if(j>i) {
            for(int k=i;k<j;k++) {            //x[j]�Ƿ���x[i..j-1]��Ԫ����ͬ 
                if(x[k]==x[j]) return true;      //����ͬ�򷵻���
            }
        }
        return false;                            //ȫ������ͬ���ؼ�
    }
};

