struct Cmp {
  bool operator()(const vector<int>&a, const vector<int>&b) {
      return a[1]<b[1];                 //���ڰ��Ҷ˵��������
    }
};
class Solution {
public:
  int eraseOverlapIntervals(vector<vector<int>>& intervals) {
      int n=intervals.size();
      if(n<=1) return 0;
      sort(intervals.begin(),intervals.end(),Cmp());
      int ans=1;                           //��ʾ��������ĸ�������ʼΪ1
      int preend=intervals[0][1];           //�������0���Ҷ˵�
      for (int i=1;i<n;i++) {               //����intervals
          if (intervals[i][0]>=preend) {        //��ǰ�����Ǽ�������(���ص�)
            ans++;
              preend=intervals[i][1];
          }
        }
        return n-ans;
    }
};

