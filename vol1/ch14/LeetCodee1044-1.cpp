const int MAXN=30010;           //n�����ȡֵ
class SuffixA {     												//��׺������
	string s;
	int n;
	vector<int> sa,rank,height;
public:
    SuffixA(string&s):s(s) {                	//���캯��
        n=s.length();
  	}
    void getsa() {                              //�����׺����sa
    	sa=vector<int>(MAXN);
    	rank=vector<int>(MAXN);		
		vector<int> tmp=vector<int>(MAXN);
		//��ʼ������
		for(int i=0;i<n;i++) {
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
        sort(sa.begin(),sa.begin()+n,cmp);  // ע�⣺ֻ���� n������������ sa ����  
  
        // ��������  
        tmp[sa[0]]=0;  
        for (int i=1;i<n;i++) {  
            tmp[sa[i]]=tmp[sa[i-1]]+(cmp(sa[i-1],sa[i])?1:0);  
        }  
        swap(rank,tmp);  
    }  
	}
	void getheight() {                     //��height����
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
    string solve() {
       int start=0;
       int maxlen=0;
        for(int j=0;j<n;j++){
            if(height[j]>maxlen){
                maxlen=height[j];
                start=sa[j];
            }
        }
        return s.substr(start,maxlen);
    }
};
class Solution {
public:
    string longestDupSubstring(string&s) {
        SuffixA sf(s); 
        sf.getsa();
        sf.getheight();
        return sf.solve();
    }
};

