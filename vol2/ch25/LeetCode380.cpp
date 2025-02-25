class RandomizedSet{
   vector<int> nums;                   					//���ȫ��Ԫ��
        unordered_map<int,int> hmap;               //<����,����>��ϣӳ��
    public:
    RandomizedSet() { }
        bool insert(int val) {                              //����val
        if(hmap.find(val)==hmap.end()) {          //Ԫ�ز�����ʱ����
            nums.push_back(val);                //��numsĩβ����val
            hmap[val]=nums.size()-1;            //val������Ϊn-1
            return true;
        }
        return false;
    }
    bool remove(int val) {                              //ɾ��val
        if(hmap.find(val)!=hmap.end()) {          //�ҵ�key
            int i=hmap[val];                           //�ҵ�val������i
            int lastk=nums[nums.size()-1];              //��ĩβ�ؼ���lastk
            nums[i]=lastk;                          //��ĩβ�ؼ����Ƶ�i������
            hmap[lastk]=i;						//����hmap[lastk]
            hmap.erase(val);                           //ɾ��val�ؼ���
            nums.pop_back();                //��numsĩβԪ��ɾ��
            return true;
        }
        return false;
    }
    int getRandom() {                       //�������һ��key
        int j=rand()%nums.size();                //����0~n-1�������
        return nums[j];
    }
};

