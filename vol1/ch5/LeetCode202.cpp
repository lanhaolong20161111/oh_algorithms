class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> hset;
        while (n!=1 && !hset.count(n)) {
            hset.insert(n);
            n=getnext(n);
        }
        return n==1;
    }
    int getnext(int m) {
        int ans=0;
        while(m>0) {
            int tmp=m%10;
            ans+=tmp*tmp;
            m=m/10;
        }
        return ans;
    }
};

