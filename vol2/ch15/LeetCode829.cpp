class Solution {
public:
    int consecutiveNumbersSum(int n) {
        int ans=0;
        for (int k=1;k*(k+1)<=2*n; k++) {
            if (judge(n, k)) ans++;
        }
        return ans;
    }
      bool judge(int n, int k) {
        if (k%2==1)				//k为奇数
            return n%k==0;
        else								//k为偶数
            return n%k !=0 && 2*n%k==0;
    }
};

