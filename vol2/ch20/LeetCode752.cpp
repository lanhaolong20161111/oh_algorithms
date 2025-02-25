struct QNode {                      //优先队列结点类型
  string s;       //数字字符串
      int f,g,h;    //启发式函数值
      bool operator<(const QNode &s) const {
          return f>s.f;                   //f越小越优先出队
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
                      if (ns==target) return e.g+1;           //找到目标
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
      char prev(char x) {                 //x逆时针方向旋转
          return x=='0'?'9':x-1;
      }
      char succ(char x) {                 //x顺时针方向旋转
          return x=='9'?'0':x+1;
      }
    vector<string> getnexts(string& s) {      //枚举s通过一次旋转得到的数字串
          vector<string> ret;
          for (int i=0;i<4;i++) {             //旋转每个数字符
              char c=s[i];
              s[i]=prev(c);               //逆时针方向旋转s[i]
              ret.push_back(s);               //旋转结果存入ret
              s[i]=succ(c);               //顺时针方向旋转s[i]
              ret.push_back(s);               //旋转结果存入ret
              s[i]=c;
          }
          return ret;
      }
   int geth(string& s,string& target) {       //计算启发函数值
      int h=0;
          for (int i=0;i<4;i++) {
              int dist=abs(int(s[i])-int(target[i]));
              h+=min(dist,10-dist);
          }
          return h;
      }
};

