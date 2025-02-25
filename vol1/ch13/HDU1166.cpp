#include<iostream>
#include<vector> 
using namespace std;
#define lowbit(x) ((x)&-(x))
class BIT {							//��״������ 
    vector<int> tree;             	//��״����Ϊtree[1..n]
    int n;
public:
    BIT() {}
    void Create(vector<int> &a) {		//��a[1..n]������״����
        n=a.size();
        tree.resize(n+1);
        for (int i=1;i<=n;i++) {
            tree[i]+=a[i];
            if (i+lowbit(i)<=n)
                tree[i+lowbit(i)]+=tree[i]; 
        }
    }
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
int main() {
  	char op[6];
  	int t,n,i,j;
  	cin >> t;
  	for (int cas=1;cas<=t;cas++) {
		cin >> n;
		vector<int> a(n+1,0);
      	for (int i=1;i<=n;i++)
        	scanf ("%d",&a[i]);
        printf ("Case %d:\n",cas);
        BIT bit;
        bit.Create(a);
      	while(~scanf ("%s",op)) {
           	if (op[0]=='E') break;
        	scanf ("%d%d",&i,&j);
           	if (op[0]=='Q')
             printf ("%d\n",bit.Sum(j)-bit.Sum(i-1));
           else if (op[0]=='A')
                bit.UpdateOne(i,j);
           else bit.UpdateOne(i,-j);
      } 
  }
 return 0;
}

