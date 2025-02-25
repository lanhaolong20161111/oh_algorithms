class ZigzagIterator {
    queue<int> qu;
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {		//构造函数产生qu
        int m=v1.size();
        int n=v2.size();
        int i=0,j=0;
        while(i<m && j<n){
            qu.push(v1[i]); i++;
            qu.push(v2[j]); j++;
        }
        while(i<m) {
            qu.push(v1[i]); i++;
        }
        while(j<n) {
            qu.push(v2[j]);  j++;
        }
    }

    int next() {
        int t=qu.front();qu.pop();
        return t;
    }

    bool hasNext() {
        return !qu.empty();
    }
};

