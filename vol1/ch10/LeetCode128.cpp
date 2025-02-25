class Solution {
    const int FLAG=0x3f3f3f3f;
    unordered_map<int,int> parent;    //��¼ÿ�����ĸ����
    unordered_map<int,int> cnt;         //�����е���������
public:
    int longestConsecutive(vector<int>& nums) {
        Init(nums);
        int n=nums.size();
        for (int i=0;i<n;i++) {
            if (Find(nums[i]+1)!=FLAG)  //������nums[i]+1
                Union(nums[i],nums[i]+1);   //����ϲ�
        }
        int ans=0;
        for (int i=0;i<n;i++) {         //����������������
            ans=max(ans,cnt[nums[i]]);
        }
        return ans;
    }
    void Init(vector<int>& nums) {              //���鼯��ʼ��
        for (int i=0;i<nums.size();i++) {
            parent[nums[i]]=nums[i];
            cnt[nums[i]]=1;
        }
    }
    int Find(int x) {                          //�ݹ��㷨�����鼯�в���x���ĸ����
        if(parent.count(x)==0)  //nums������x
            return FLAG;
        if (x!=parent[x])
            parent[x]=Find(parent[x]);          //·��ѹ��
        return parent[x];
    }
    void Union(int x,int y) {                     //���鼯��x��y���������ϵĺϲ�
        int rx=Find(x);
        int ry=Find(y);
        if (rx==ry) return;                       //x��y����ͬһ���������
        parent[rx]=ry;
        cnt[ry]+=cnt[rx];
    }
};

