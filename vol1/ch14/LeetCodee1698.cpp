const int MAXN=30010;           //n�����ȡֵ
class SuffixA {                         //��׺������
    string s;
    int n;
    int cnt[MAXN];
    int sa[MAXN];
    int rank[MAXN];
    int height[MAXN];
    int tmp[MAXN];              //��ʱ�ռ�
public:
    SuffixA(string&s):s(s) {                //���캯��
        n=s.length();
  	}
    void getsa() {                              //�����׺����sa
            int maxbuk=256;                     //Ͱ����
        for(int i=0;i<maxbuk;i++) cnt[i]=0;         //Ͱ����
        for(int i=0;i<n;i++) cnt[s[i]]++;
        for(int i=1;i<maxbuk;i++) cnt[i]+=cnt[i-1];
        for(int i=n-1;i>=0;i--) sa[--cnt[s[i]]]=i;
        rank[sa[0]]=0;                              //��ʼ����Ϊ0
        int num=0;                                  //����������1��ʼ
        for(int i=1;i<n;i++) {
            if(s[sa[i-1]]==s[sa[i]])   rank[sa[i]]=num; 
            else rank[sa[i]]=++num;
        }
        for(int len=1;len<n;len*=2) {               	//��������
            int* pos=tmp;                       //��ǰ���а�y������sa
            int p=0;
            for(int i=n-len;i<n;i++)            //Խ��yӦ��������ǰ��
                pos[p++]=i;
            for(int i=0;i<n;i++) {
                if(sa[i]>=len)                      //δԽ��y����Ӧ��xΪsa[i]-len
                    pos[p++]=sa[i]-len;
            }
            for(int i=0;i<maxbuk;i++) cnt[i]=0;                 //��x����Ͱ����
            for(int i=0;i<n;i++) cnt[rank[pos[i]]]++;
            for(int i=1;i<maxbuk;i++) cnt[i]+=cnt[i-1];
            for(int i=n-1;i>=0;i--)                     //����Ͱ����Ľ�������׺����
                sa[--cnt[rank[pos[i]]]]=pos[i];
            int*nrank=tmp;                    //����������
            nrank[sa[0]]=0;
            num=1;
            for(int i=1;i<n;i++) {
                if(rank[sa[i-1]]==rank[sa[i]] && max(sa[i-1],sa[i])+len<n 
                    && rank[sa[i-1]+len]==rank[sa[i]+len])
                        nrank[sa[i]]=num-1;
                    else
                        nrank[sa[i]]=num++;
            }
            for(int i=0;i<n;i++) rank[i]=nrank[i];  //��nrank���Ƶ�rank
            if(num>=n) break;                               //����ȫ��ȷ��ʱ����
            maxbuk=num;                                     //�޸�Ͱ����
        }
    }
     void getheight() {                     //��height����
        int k=0;
        for (int i=0;i<n;i++) {
            if (rank[i]==0) continue;
            if (k>0) k--;
            int j=sa[rank[i]-1];
            while (j+k<n && i+k<n && s[i+k]==s[j+k]) k++;
            height[rank[i]]=k;
        }
    }
    int solve() {
        int ans=(1+n)*n/2;
        for(int i=0;i<n;i++) ans-=height[i];
        return ans;
    }
};
class Solution {
public:
    int countDistinct(string&s) {
        SuffixA sf(s);
        sf.getsa();
        sf.getheight();
        return sf.solve();
    }
};

