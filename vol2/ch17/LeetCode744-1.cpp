class Solution {
public:
    char nextGreatestLetter(vector<char>& letters,char target) {	//查找到区间为空
        int n=letters.size();
        int low=0,high=n-1;
        while(low<=high) {
            int mid=(low+high)/2;
            if(letters[mid]>target) high=mid-1;
            else low=mid+1;
        }
        if(low>=n) return letters[0];		//未找到target
        else return letters[low];				//找到target
    }
};

