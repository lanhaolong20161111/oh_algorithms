struct Cmp {
    bool operator()(vector<int>&a,vector<int> &b) {
        return a[1]<b[1];       //按右端点递增排序
    }
};
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n=points.size();
        if(n==1) return 1;
        sort(points.begin(), points.end(),Cmp()); 
        int ans=0;                  //存放答案
        int preend=points[0][1];
        ans++;                      //选择points[0]
        for(int i=1;i<n;i++) {
            if(points[i][0]>preend) {
                ans++;
                preend=points[i][1];
            }
        }
        return ans;
    }
};

