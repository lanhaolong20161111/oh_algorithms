struct PROJ {						//��Ŀ�ṹ��
  	int cap;  //�����ʱ�
  	int pro;  //������
  	PROJ(int c,int p):cap(c),pro(p) {}
  	bool operator<(const PROJ&s) {
    	return cap<s.cap;     //���ڰ������ʱ���������
  	}
	};
class Solution {
public:
  	int findMaximizedCapital(int k,int w,vector<int>&profits,vector<int>& capital) {
  		int n=capital.size();
  		vector<PROJ> proj;				//��Ŀ��
  	for(int i=0;i<n;i++)
    	proj.push_back(PROJ(capital[i],profits[i]));
  	priority_queue<int> pqu;      //������Խ��Խ���ȳ���
  	sort(proj.begin(),proj.end());    //����
  	int ans=w;            //��ǰ������ʱ�
  	int i=0;                      //����proj
  	for(int j=0;j<k;j++) {        //���ȡk����Ŀ
   		while(i<n && proj[i].cap<=ans) {
     		pqu.push(proj[i].pro);    //���������������ʱ�Ҫ��Ľ���
        	i++;
     	}
    	if(!pqu.empty()) {      //ѡ������������Ŀ
      		ans+=pqu.top(); pqu.pop();//�������ʱ�
   		}
  		else break;
   	}
  	return ans;
	}
};

