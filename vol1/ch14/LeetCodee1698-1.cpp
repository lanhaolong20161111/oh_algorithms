const int MAXN=30010;           //n的最大取值
class SuffixA {     												//后缀数组类
	string s;
	int n;
	vector<int> sa,rank,height;
public:
    SuffixA(string&s):s(s) {                	//构造函数
        n=s.length();
  	}
    void getsa() {                              //计算后缀数组sa
    	sa=vector<int>(MAXN);
    	rank=vector<int>(MAXN);		
		vector<int> tmp=vector<int>(MAXN);
		for(int i=0;i<n;i++) {				//初始化排名
			sa[i]=i;
			rank[i]=s[i];
		}
	    for (int len=1;len<n;len*= 2) {  
            auto cmp=[&](int i, int j) {  
            if (rank[i]!=rank[j])  
                return rank[i]<rank[j];  
            else {  
                int ri=i+len<n?rank[i+len]:-1;  
                int rj=j+len<n?rank[j+len]:-1;  
                return ri<rj;  
            }  
        };  
        sort(sa.begin(),sa.begin()+n,cmp);  // 注意：只排序到n，而不是整个sa数组  
          // 更新排名  
        tmp[sa[0]]=0;  
        for (int i=1;i<n;i++) {  
            tmp[sa[i]]=tmp[sa[i-1]]+(cmp(sa[i-1],sa[i])?1:0);  
        }  
        swap(rank,tmp);  
    }  
	}
	void getheight() {                     //求height数组
		height=vector<int>(MAXN,0);
        int k=0;
        for (int i=0;i<n;i++) {
            if (rank[i]==0) continue;
            if (k>0) k--;
            int j=sa[rank[i]-1];
            while(j+k<n && i+k<n && s[i+k]==s[j+k]) k++;
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

