class Solution {
public:
    char nextGreatestLetter(vector<char>& letters,char target) {			//��STL����
        int i=upper_bound(letters.begin(),letters.end(),target)-letters.begin();
        if(i>=letters.size()) return letters[0];        //δ�ҵ�target
        else return letters[i];             //�ҵ�target
    }
};

