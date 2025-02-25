class Solution {
public:
    int totalNQueens(int n) {
        vector<int> x;
        for(int i=0;i<n;i++) x.push_back(i);
        int ans=0;
        do {
            if(isaqueen(n,x)) ans++;
        } while(next_permutation(x.begin(),x.end()));
        return ans;
    }
    bool isaqueen(int n,vector<int>&x) {    //�ж�x�Ƿ���n�ʺ������һ����
        for(int i=1;i<n;i++) {
            if(!valid(i,x)) return false;
        }
        return true;
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

