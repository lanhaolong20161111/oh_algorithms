class Solution {
public:
    char nextGreatestLetter(vector<char>& letters,char target) {	//查找到区间仅含一个元素
        int n=letters.size();
        int low=0,high=n;
        while(low<high) {
            int mid=(low+high)/2;
            if(letters[mid]>target) high=mid;
            else low=mid+1;
        }
        if(low>=n) return letters[0];       //未找到target
        else return letters[low];               //找到target
    }
};

