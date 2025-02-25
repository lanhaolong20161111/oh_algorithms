#define lowbit(x) ((x)&-(x))
class BIT {
    vector<int> tree;                       //��״����Ϊtree[1..n]
    int n;
public:
    BIT(int n):n(n),tree(n+1,0) {}
    void UpdateOne(int i,int x) {           //�����޸�
        while (i<=n) {
            tree[i]+=x;
            i+=lowbit(i);
        }
    }
    int Sum(int i) {                        //��ǰ׺��
        int ans=0;
        while (i>0) {
            ans+=tree[i];
            i-=lowbit(i);
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> processQueries(vector<int>& queries,int m) {
        int n=queries.size();
        BIT bit(m+n);
        vector<int> pos(m+1);
        for (int i=1;i<=m;i++) {
            pos[i]=n+i;         				//1��m������λ�õ�ӳ��
            bit.UpdateOne(n+i,1);		//����״���������1��m����
        }
        vector<int> ans;
        for (int j=0;j<n;j++) {
            int i=pos[queries[j]];			//��queries[j]��pos�е�����
            ans.push_back(bit.Sum(i)-1);		//��queries[j]��P�еĵ�λ��
            bit.UpdateOne(i,-1);    //��λ��i�����ƶ�����ǰ��
            pos[queries[j]]=n-j;
            bit.UpdateOne(n-j,1);
        }
        return ans;
    }
};

