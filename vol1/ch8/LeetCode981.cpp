class TimeMap {
    unordered_map<string,map<int,string>> hmap; //数据结构
public:
    TimeMap() { }
    
    void set(string key, string value, int timestamp) {
        hmap[key][timestamp]=value;
    }
    
    string get(string key,int timestamp) {
        if(hmap[key].empty()) return "";		//不存在该key的元素时
        auto it=hmap[key].begin();          //指向hmap[key]的首元素
        if(timestamp<it->first)				//所有元素的时间均大于timestamp
            return "";
        it=hmap[key].upper_bound(timestamp);   //找到第一个更大时间戳的元素
        it--;
        return it->second;
    }
};

