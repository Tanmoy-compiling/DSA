#include <bits/stdc++.h>
using namespace std;

void printPrefix(vector<int> prefix){
    for(int i = 0;i<prefix.size();i++){
        cout<<prefix[i]<<" ";
    }
    cout<<endl;
}

int counterCheck(vector<int> prefix,int target,int si,int ci, int temp){
    if(ci==prefix.size()){
        return 0;
    }
    if(prefix[ci]-prefix[temp]==target || prefix[ci]==target){
        return counterCheck(prefix,target,ci,ci+1,ci)+1;
    }
    if(temp == ci)
        return counterCheck(prefix,target,si,ci+1,si);

    return counterCheck(prefix,target,si,ci,temp+1);
}

class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        vector<int> prefix(nums.size());
        prefix[0]=nums[0];
        for(int i = 1;i<nums.size();i++){
            if(nums[i]==target){
                prefix[i]=nums[i];
                continue;
            }
            else if(prefix[i-1]==target){
                prefix[i]=nums[i];
                continue;
            }
            else{
                prefix[i]=prefix[i-1]+nums[i];
            }
        }
        printPrefix(prefix);
        int count = 0;
        count = counterCheck(prefix,target,0,1,0);
        if(prefix[0]==target) count++;
        return count;
    }
};

int main(){
    Solution a;
    vector<int> nums = {0,2,5,7,10};
    int count = a.maxNonOverlapping(nums,12);
    cout<<count<<endl;

}