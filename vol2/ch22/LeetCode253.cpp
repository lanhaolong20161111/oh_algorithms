struct Cmp {
    bool operator()(const vector<int>&a,const vector<int>&b) const {
        return a[0]<b[0];                   //���ڰ����鿪ʼʱ���������
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
            if (A[i][0]>=pqu.top())                       //����ʱ����
                pqu.pop();
            pqu.push(A[i][1]);
        }
        return pqu.size();
    }
};

