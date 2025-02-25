struct Cmp {
  bool operator()(const vector<int>&a, const vector<int>&b) {
      return a[0]<b[0];           //���ڰ���˵��������
    }
};
class Solution {
public:
    int videoStitching(vector<vector<int>> &clips,int time) {
        int n=clips.size();
        sort(clips.begin(),clips.end(),Cmp());
        int ans=0;              					//��Ŵ�
        int preend=0;           					//��ǰѡ��Ƭ�ε��Ҷ˵�,��ʼ������������[0,0]
        int i=0;
        while (preend<time) {
            int next=preend; 									//�����Ҷ˵�
            while (i<n && clips[i][0]<=preend) {    //���ص����������Ҷ˵�
                next=max(next,clips[i][1]);
                i++;
            }
            ans++;              //ѡ������Ҷ˵��Ƭ��
            if (next==preend)   //�Ҳ�����Ƭ�Σ��޷��ϳ���Ƶ
                return -1; 
            preend=next;
        }
        return ans;
    }
};

