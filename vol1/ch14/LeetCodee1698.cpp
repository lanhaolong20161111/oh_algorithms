const int MAXN=30010;           //n的最大取值
class SuffixA {                         //后缀数组类
    string s;
    int n;
    int cnt[MAXN];
    int sa[MAXN];
    int rank[MAXN];
    int height[MAXN];
    int tmp[MAXN];              //临时空间
public:
    SuffixA(string&s):s(s) {                //构造函数
        n=s.length();
  	}
    void getsa() {                              //计算后缀数组sa
            int maxbuk=256;                     //桶个数
        for(int i=0;i<maxbuk;i++) cnt[i]=0;         //桶排序
        for(int i=0;i<n;i++) cnt[s[i]]++;
        for(int i=1;i<maxbuk;i++) cnt[i]+=cnt[i-1];
        for(int i=n-1;i>=0;i--) sa[--cnt[s[i]]]=i;
        rank[sa[0]]=0;                              //初始排名为0
        int num=0;                                  //后面排名从1开始
        for(int i=1;i<n;i++) {
            if(s[sa[i-1]]==s[sa[i]])   rank[sa[i]]=num; 
            else rank[sa[i]]=++num;
        }
        for(int len=1;len<n;len*=2) {               	//倍增过程
            int* pos=tmp;                       //当前趟中按y排序后的sa
            int p=0;
            for(int i=n-len;i<n;i++)            //越界y应该排在最前面
                pos[p++]=i;
            for(int i=0;i<n;i++) {
                if(sa[i]>=len)                      //未越界y，对应的x为sa[i]-len
                    pos[p++]=sa[i]-len;
            }
            for(int i=0;i<maxbuk;i++) cnt[i]=0;                 //对x进行桶排序
            for(int i=0;i<n;i++) cnt[rank[pos[i]]]++;
            for(int i=1;i<maxbuk;i++) cnt[i]+=cnt[i-1];
            for(int i=n-1;i>=0;i--)                     //根据桶排序的结果构造后缀数组
                sa[--cnt[rank[pos[i]]]]=pos[i];
            int*nrank=tmp;                    //计算新排名
            nrank[sa[0]]=0;
            num=1;
            for(int i=1;i<n;i++) {
                if(rank[sa[i-1]]==rank[sa[i]] && max(sa[i-1],sa[i])+len<n 
                    && rank[sa[i-1]+len]==rank[sa[i]+len])
                        nrank[sa[i]]=num-1;
                    else
                        nrank[sa[i]]=num++;
            }
            for(int i=0;i<n;i++) rank[i]=nrank[i];  //将nrank复制到rank
            if(num>=n) break;                               //排名全部确定时结束
            maxbuk=num;                                     //修改桶个数
        }
    }
     void getheight() {                     //求height数组
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

