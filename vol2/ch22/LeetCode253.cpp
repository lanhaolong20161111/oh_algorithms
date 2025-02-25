struct Cmp {
    bool operator()(const vector<int>&a,const vector<int>&b) const {
        return a[0]<b[0];                   //用于按会议开始时间递增排序
    }
};
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& A) {
        int n=A.size();
        priority_queue<int,vector<int>,greater<int>> pqu;
        sort(A.begin(),A.end(),Cmp());
        pqu.push(A[0][1]);
        for (int i=1;i<n;i++) {
            if (A[i][0]>=pqu.top())                       //兼容时出队
                pqu.pop();
            pqu.push(A[i][1]);
        }
        return pqu.size();
    }
};

