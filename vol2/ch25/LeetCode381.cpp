class RandomizedCollection {
private:   
    vector<int> nums;                               //���ȫ��Ԫ��
    unordered_map<int,unordered_set<int>> hmap;     //���Ԫ����nums�е�����
public:
        RandomizedCollection() {}                          //��ʼ��

        bool insert(int val) {                               //����val
            hmap[val].insert(nums.size());                  //val���뵽numsĩβ
            nums.push_back(val);
            if(hmap[val].size()==1)
                return true;                                    //valֵ�ĸ���Ϊ1������true
            else
                return false;                                   //valֵ�ĸ�������1������false
        }

        bool remove(int val) {                                //ɾ��val
            if(hmap[val].empty())                              //û���ҵ�val����false
                return false;
            auto it=hmap[val].begin();                   //��hmap[val]�ҵ�һ��val��λ��
            int i=*it;                                     //��һ��val������
            hmap[val].erase(it);                           //��hmap[val]��ɾ����val
            if(hmap[val].empty()) hmap.erase(val);      //hmap[val]Ϊ��ɾ����Ԫ��
            if(i!=nums.size()-1) {                  //ɾ���Ĳ���nums��ĩβԪ��ʱ
                int lastk=nums[nums.size()-1];              //��ĩβ�ؼ���lastk
                nums[i]=lastk;                             //��Ԫ��lastk�Ƶ�����i��
                hmap[lastk].erase(nums.size()-1);           //hmap[lastk]��ɾ��n-1
                hmap[lastk].insert(i);
            }
            nums.pop_back();                                    //��nums��ɾ��ĩβԪ��
            return true;
        }

        int getRandom() {                                 //�������Ԫ��
           int j=rand()% nums.size(); // 0~n
            return nums[j];
        }
};

