class Solution {
public:
    char nextGreatestLetter(vector<char>& letters,char target) {			//用STL函数
        int i=upper_bound(letters.begin(),letters.end(),target)-letters.begin();
        if(i>=letters.size()) return letters[0];        //未找到target
        else return letters[i];             //找到target
    }
};

