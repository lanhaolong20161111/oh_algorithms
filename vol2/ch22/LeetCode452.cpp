struct Cmp {
    bool operator()(vector<int>&a,vector<int> &b) {
        return a[1]<b[1];       //���Ҷ˵��������
    }
};
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n=points.size();
        if(n==1) return 1;
        sort(points.begin(), points.end(),Cmp()); 
        int ans=0;                  //��Ŵ�
        int preend=points[0][1];
        ans++;                      //ѡ��points[0]
        for(int i=1;i<n;i++) {
            if(points[i][0]>preend) {
                ans++;
                preend=points[i][1];
            }
        }
        return ans;
    }
};

