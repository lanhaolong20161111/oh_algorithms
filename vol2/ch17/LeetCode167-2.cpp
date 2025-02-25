class Solution {
public:
    vector<int> twoSum(vector<int>& numbers,int target) {
        int n=numbers.size();
        for(int i=0;i<n-1;i++) {
            auto it=lower_bound(numbers.begin()+i+1,numbers.end(),target-numbers[i]);
            int j=it-numbers.begin();
            if(it!=numbers.end() && numbers[i]+*it==target)
                return {i+1,j+1};
        }
        return {0,0};
    }
};

