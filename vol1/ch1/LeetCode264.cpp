class Solution {
public:
    int nthUglyNumber (int n) {
        vector<int> ans(n+1);
        ans[1]=1;
        int p2=1, p3=1, p5=1;
        for(int i=2;i<=n;i++) {
            int a=ans[p2]*2;
            int b=ans[p3]*3;
            int c=ans[p5]*5;
            int mind=min(a,min(b,c));   			//求a,b,c中最小整数mind
            if(mind==a) p2++;
            if(mind==b) p3++;
            if(mind==c) p5++;
            ans[i]=mind;
        }
        return ans[n];
    }
};

