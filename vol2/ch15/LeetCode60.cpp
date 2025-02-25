class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> x;
        for(int i=1;i<=n;i++) x.push_back(i);
        int cnt=1;
        while(cnt<k) {
            cnt++;
            next_permutation(x.begin(),x.end());
        }
        string ret="";
        for(int e:x) ret+=to_string(e);
        return ret;
    }
};

