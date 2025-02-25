class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==1 || n==2) return true;
        else if(n<=0 || n%2==1) return false;
        else return isPowerOfTwo(n/2);
    }
};

