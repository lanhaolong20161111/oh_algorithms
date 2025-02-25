class Solution {
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
        vector<int> ans;
        vector<int> x(3,0);
        x[0]=arr1[0];x[1]=arr2[0];x[2]=arr3[0];
        int i=0,j=0,k=0;
        while(i<arr1.size() && j<arr2.size() && k<arr3.size()) {
            if(x[0]==x[1] && x[1]==x[2]) {      //3个元素均相等
                if(ans.empty() || x[0]!=ans.back())
                    ans.push_back(x[0]);
                i++; j++; k++;
                if(i<arr1.size())
                    x[0]=arr1[i];
                if(j<arr2.size())
                    x[1]=arr2[j];
                if(k<arr3.size())
                    x[2]=arr3[k];
            }
            else {
                int mini=minx(x);
                switch(mini) {
                    case 0: i++;
                            if(i<arr1.size())
                                x[0]=arr1[i];
                            break;
                    case 1: j++;
                            if(j<arr2.size())
                                x[1]=arr2[j];
                            break;
                    case 2: k++;
                            if(k<arr3.size())
                                x[2]=arr3[k];
                            break;
                }
            }
        }
        return ans;
    }

    int minx(vector<int>&x) {       //求x中最小元素的段号
        int mini=0;
        for(int i=1;i<3;i++) {
            if(x[i]<x[mini])
                mini=i;
        }
        return mini;
    }
};

