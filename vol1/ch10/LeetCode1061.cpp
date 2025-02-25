class Solution {
    vector<int> parent;         //���鼯
public:
    string smallestEquivalentString(string s1,string s2,string baseStr) {
        Init(26);
        for(int i=0;i<s1.size();i++) {
            int x=s1[i]-'a';
            int y=s2[i]-'a';
            Union(x,y);
        }
        string ans="";
        for(int i=0;i<baseStr.size();i++) {
            int x=baseStr[i]-'a';
            int rx=Find(x);
            ans+=(char)(rx+'a');
        }
        return ans;
    }
    void Init(int n) {                              //���鼯��ʼ��
        parent=vector<int>(n);
        for (int i=0;i<n;i++)
            parent[i]=i;
    }

    int Find(int x) {                             //�ݹ��㷨�����鼯�в���x���ĸ����
        if (x!=parent[x])
            parent[x]=Find(parent[x]);          //·��ѹ��
        return parent[x];
    }
    void Union(int x,int y) {                       //���鼯��x��y���������ϵĺϲ�
        int rx=Find(x);
        int ry=Find(y);
        if (rx==ry) return;                           //x��y����ͬһ���������
        if (rx<ry)  parent[ry]=rx;                 //��С��ŵĽ����Ϊ��
        else  parent[rx]=ry;
    }
};

