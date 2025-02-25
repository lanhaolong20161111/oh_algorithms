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
    bool isaqueen(int n,vector<int>&x) {    //判断x是否是n皇后问题的一个解
        for(int i=1;i<n;i++) {
            if(!valid(i,x)) return false;
        }
        return true;
    }
    bool valid(int i,vector<int>&x) {       //测试(i,x[i])位置是否与前面的皇后不冲突
        if (i==0) return true;
        int k=0;
        while (k<i) {                                       //k=0～i-1是已放置了皇后的行
            if ((x[k]==x[i]) || (abs(x[k]-x[i])==abs(k-i))) 
                return false;                                   //(i,x[i])与皇后k有冲突
            k++;
        }
        return true;
    }
};

