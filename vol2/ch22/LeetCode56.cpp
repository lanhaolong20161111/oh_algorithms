struct Cmp {
  bool operator()(const vector<int>&a, const vector<int>&b) {
      return a[0]<b[0];           //���ڰ���˵��������
    }
};
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
      int n=intervals.size();
        if (n<=1) return intervals;
        sort(intervals.begin(),intervals.end(),Cmp());
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        for (int i=1;i<n;i++) {           //��i����intervals
          int curs=intervals[i][0];       //��ǰ����[curs,cure)
          int cure=intervals[i][1];
          if (ans.back()[1]<curs)       //���ཻ
            ans.push_back({curs,cure});
          else                  //�ཻ���ϲ�
            ans.back()[1]=max(ans.back()[1],cure);
      }
        return ans;
    }
};

