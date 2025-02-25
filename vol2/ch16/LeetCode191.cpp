class Solution {
public:
    int hammingWeight(uint32_t n) {
        if(n==0) return 0;
        if(n&0x1) return 1+hammingWeight(n/2);
        else return hammingWeight(n/2);
    }
};

