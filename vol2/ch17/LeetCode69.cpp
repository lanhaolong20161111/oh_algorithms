class Solution {
public:
    int mySqrt(int x) {
        if (x==0) return 0;
        if (x<4) return 1;
        int low=2,high=x/2;
        while(low<=high) {
            int mid=(low+high)/2;
            if (x/mid<mid)  high=mid-1;
            else if (x/(mid+1)<(mid+1))  return mid;
            else low=mid+1;
        }
        return 0;
    }
};

