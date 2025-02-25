struct PROJ {						//项目结构体
  	int cap;  //启动资本
  	int pro;  //纯利润
  	PROJ(int c,int p):cap(c),pro(p) {}
  	bool operator<(const PROJ&s) {
    	return cap<s.cap;     //用于按启动资本递增排序
  	}
	};
class Solution {
public:
  	int findMaximizedCapital(int k,int w,vector<int>&profits,vector<int>& capital) {
  		int n=capital.size();
  		vector<PROJ> proj;				//项目表
  	for(int i=0;i<n;i++)
    	proj.push_back(PROJ(capital[i],profits[i]));
  	priority_queue<int> pqu;      //按利润越大越优先出队
  	sort(proj.begin(),proj.end());    //排序
  	int ans=w;            //当前的最多资本
  	int i=0;                      //遍历proj
  	for(int j=0;j<k;j++) {        //最多取k个项目
   		while(i<n && proj[i].cap<=ans) {
     		pqu.push(proj[i].pro);    //将所有满足启动资本要求的进队
        	i++;
     	}
    	if(!pqu.empty()) {      //选择最大利润的项目
      		ans+=pqu.top(); pqu.pop();//增加总资本
   		}
  		else break;
   	}
  	return ans;
	}
};

