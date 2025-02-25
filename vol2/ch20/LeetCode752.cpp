struct QNode {                      //���ȶ��н������
  string s;       //�����ַ���
      int f,g,h;    //����ʽ����ֵ
      bool operator<(const QNode &s) const {
          return f>s.f;                   //fԽСԽ���ȳ���
      }
};
class Solution {
public:
  int openLock(vector<string>& deadends, string target) {
      if (target=="0000") return 0;
          unordered_set<string> dead(deadends.begin(),deadends.end());
          if (dead.count("0000")==1) return -1;
          priority_queue<QNode> pqu;
          QNode e,e1;
          e.s="0000";e.g=0;
          e.h=geth(e.s,target);
          e.f=e.g+e.h;
          pqu.push(e);
          unordered_set<string> visited={"0000"};
          while (!pqu.empty()) {
              e=pqu.top();pqu.pop();
              string s=e.s;
              for (string ns:getnexts(s)) {
                  if (visited.count(ns)==0 && dead.count(ns)==0) {
                      if (ns==target) return e.g+1;           //�ҵ�Ŀ��
                      e1.s=ns; e1.g=e.g+1;
                      e1.h=geth(ns,target);
                      e1.f=e1.g+e1.h;
                      pqu.push(e1);
                      visited.insert(ns);
                  }
              }
          }
          return -1;
      }
      char prev(char x) {                 //x��ʱ�뷽����ת
          return x=='0'?'9':x-1;
      }
      char succ(char x) {                 //x˳ʱ�뷽����ת
          return x=='9'?'0':x+1;
      }
    vector<string> getnexts(string& s) {      //ö��sͨ��һ����ת�õ������ִ�
          vector<string> ret;
          for (int i=0;i<4;i++) {             //��תÿ�����ַ�
              char c=s[i];
              s[i]=prev(c);               //��ʱ�뷽����תs[i]
              ret.push_back(s);               //��ת�������ret
              s[i]=succ(c);               //˳ʱ�뷽����תs[i]
              ret.push_back(s);               //��ת�������ret
              s[i]=c;
          }
          return ret;
      }
   int geth(string& s,string& target) {       //������������ֵ
      int h=0;
          for (int i=0;i<4;i++) {
              int dist=abs(int(s[i])-int(target[i]));
              h+=min(dist,10-dist);
          }
          return h;
      }
};

