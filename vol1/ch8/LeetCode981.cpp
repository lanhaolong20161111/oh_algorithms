class TimeMap {
    unordered_map<string,map<int,string>> hmap; //���ݽṹ
public:
    TimeMap() { }
    
    void set(string key, string value, int timestamp) {
        hmap[key][timestamp]=value;
    }
    
    string get(string key,int timestamp) {
        if(hmap[key].empty()) return "";		//�����ڸ�key��Ԫ��ʱ
        auto it=hmap[key].begin();          //ָ��hmap[key]����Ԫ��
        if(timestamp<it->first)				//����Ԫ�ص�ʱ�������timestamp
            return "";
        it=hmap[key].upper_bound(timestamp);   //�ҵ���һ������ʱ�����Ԫ��
        it--;
        return it->second;
    }
};

