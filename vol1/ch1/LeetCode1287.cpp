class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n=arr.size();
        int c=arr[0], cnt=0;
        for (int i=0;i<n;i++) {
            if (arr[i]==c) {
                cnt++;
                if (cnt*4>n) return c;
            }
            else {
                c=arr[i];
                cnt=1;
            }
        }
        return -1;
    }
};

